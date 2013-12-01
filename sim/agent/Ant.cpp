#include "Ant.hpp"
#include "../nav/Node.hpp"
#include "../nav/NavGraphHelper.hpp"
#include "../worldobject/AntHome.hpp"
#include "../goal/AntGoal.hpp"
#include "../goal/AntEat.hpp"
#include "../goal/AntForage.hpp"
#include "../goal/AntExplore.hpp"
#include "../goal/AntMoveToNode.hpp"
#include "../util/make_unique.hpp"

#include <iostream>

// Christopher D. Canfield
// October 2013
// Ant.cpp

using cdc::Ant;
using cdc::Percept;
using cdc::GuiEventManager;
using cdc::Node;
using cdc::NavGraphHelper;
using cdc::AntHome;
using cdc::AntGoal;
using cdc::AntMoveToNode;

using std::unique_ptr;
using std::cout;
using std::endl;
using std::move;


bool Ant::wasTextureLoaded = false;
sf::Texture* Ant::texture = nullptr;


Ant::Ant(GuiEventManager& manager, AntHome& home, NavGraphHelper& graphHelper, const Node& startNode) :
		Button(manager),
		kb(home, graphHelper)
{
	if (!Ant::wasTextureLoaded)
	{
		if (Ant::texture == nullptr)
		{
			Ant::texture = new sf::Texture;
		}

		if (!Ant::texture->loadFromFile("res/ant.png"))
		{
			std::cout << "Unable to load ant image: res/ant.png" << std::endl;
		}
		else
		{
			Ant::wasTextureLoaded = true;
		}
	}

	auto antSprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(*Ant::texture));			
	setDefaultImage(std::move(antSprite));
	setOriginToCenter();

	deadAntSprite.setTexture(*Ant::texture, true);

	// Ants don't need to know about mouse move events.
	manager.removeMouseMoveListener(*this);

	goal = make_unique<AntForage>();
	setPositionToNode(startNode);
}

Ant::Ant(Ant&& other) :
	Button(move(other)),
	kb(move(other.kb)),
	stats(other.stats),
	goal(move(other.goal)),
	isSelected(other.isSelected),
	deadAntSprite(other.deadAntSprite)
{
}

Ant::~Ant()
{
}

void Ant::update(uint ticks, const Percept& percept)
{
	if (!isDead())
	{
		processHunger(ticks, stats);
		
		// Process the goal if one is set, or set a new one if not.
		if (!goal->isFinished())
		{
			auto antPercept = AntPercept(percept);
			goal->update(*this, ticks, antPercept);
		}
		else
		{
			goal = getNewGoal(stats);
		}
	}
}


void Ant::setPositionToNode(const Node& node)
{
	kb.lastNodePassed = const_cast<Node*>(&node);
	setPosition(node.getPixelX(), node.getPixelY());
}

const Node* Ant::popLastKnownFoodPosition()
{
	if (!kb.lastKnownFoodPosition.empty())
	{
		auto mostRecent = kb.lastKnownFoodPosition.front();
		kb.lastKnownFoodPosition.pop_front();
		return mostRecent;
	}
	else
	{
		return nullptr;
	}
}

uint Ant::getHunger() const
{
	return stats.hunger;
}

AntHome& Ant::getHome() const
{
	return kb.home;
}

bool Ant::isDead() const
{
	return stats.isDead;
}

void Ant::kill()
{
	onDeath();
}

Node& Ant::getNode() const
{
	return *kb.lastNodePassed;
}



void Ant::onDirectGuiEvent(const sf::Event& e)
{
	if (e.type == sf::Event::MouseButtonReleased && !isSelected)
	{
		isSelected = true;
		cout << "Ant " << getObserverId().toString() << " selected" << endl;
		cout << "  Current Goal: " << goal->toString() << endl;
	}
}

void Ant::onGuiEvent(const sf::Event& e)
{
	if (e.type == sf::Event::MouseButtonPressed && isSelected)
	{
		isSelected = false;
	}
}

void Ant::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (isDead())
	{
		target.draw(deadAntSprite, states);
	}
	else
	{
		Button::draw(target, states);
	}
}


////// Private methods //////

void Ant::onDeath()
{
	if (!stats.isDead)
	{
		if (isSelected) cout << "  Ant " << getObserverId().toString() << " has died" << endl;
		stats.isDead = true;
		deadAntSprite.setPosition(getPosition());
		deadAntSprite.setColor(sf::Color(128, 128, 128));
	}
}

void Ant::processHunger(uint ticks, AntStats& stats)
{
	if (ticks >= stats.nextHungerIncrease)
	{
		if (stats.hunger >= stats.maxHunger)
		{
			// The ant has starved to death.
			onDeath();
		}
		else
		{
			++stats.hunger;
			// Modify the hunger increase rate by between 0.75 and 1.25, to 
			// differentiate the behaviors of the ants.
			float modifier = random.getInteger(75, 125) / 100.f;
			stats.nextHungerIncrease += static_cast<uint>(stats.hungerIncreaseRate * modifier);
		}
	}
}

unique_ptr<AntGoal> Ant::getNewGoal(AntStats& stats)
{
	using std::move;

	const uint hungry = 60;

	// Look for food if hungry. This takes priority over other potential goals.
	if (stats.hunger > hungry)
	{
		auto newGoal = unique_ptr<AntEat>(new AntEat());
		if (isSelected) cout << "  Goal changed: " << newGoal->toString() << endl;
		return move(newGoal);
	}

	// The chance that the ant will explore rather than forage, from 1 to 10.
	const int exploreChance = 2;
	int decision = random.getInteger(1, 10);
	if (decision <= exploreChance)
	{
		auto newGoal = unique_ptr<AntExplore>(new AntExplore());
		if (isSelected) cout << "  Goal changed: " << newGoal->toString() << endl;
		return move(newGoal);
	}
	else
	{
		auto newGoal = unique_ptr<AntForage>(new AntForage());
		if (isSelected) cout << "  Goal changed: " << newGoal->toString() << endl;
		return move(newGoal);
	}
}


////// Struct constructors //////

Ant::AntKnowledgeBase::AntKnowledgeBase(AntHome& home, NavGraphHelper& graphHelper) :
	home(home),
	navGraphHelper(graphHelper),
	// Up to four food piles are remembered by the ant.
	lastKnownFoodPosition(4),
	lastNodePassed(nullptr)
{
}

Ant::AntStats::AntStats() :
	hungerIncreaseRate(120),	// default ticks per second is 30, so this gives a rate of 4 seconds per increase in hunger.
	hunger(0),
	nextHungerIncrease(hungerIncreaseRate),
	maxHunger(100),
	isHoldingFood(false),
	isDead(false),
	movementSpeed(2.5f)
{
}