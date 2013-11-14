#include "Ant.hpp"
#include "../nav/Node.hpp"
#include "../nav/NavGraphHelper.hpp"
#include "../worldobject/AntHome.hpp"
#include "../goal/AntGoal.hpp"
#include "../goal/AntEat.hpp"
#include "../goal/AntForage.hpp"
#include "../goal/AntExplore.hpp"

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

using std::unique_ptr;


bool Ant::wasTextureLoaded = false;
sf::Texture* Ant::texture = nullptr;


Ant::Ant(GuiEventManager& manager, AntHome& home, NavGraphHelper& graphHelper) :
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

	// Ants don't need to know about mouse move events or indirect click events.
	manager.removeMouseMoveListener(*this);
	manager.removeClickListener(*this);
}

Ant::Ant(Ant&& other) :
	Button(std::move(other)),
	kb(std::move(other.kb)),
	stats(other.stats)
{
}

Ant::~Ant()
{
}

void Ant::update(long ticks, const Percept& percept)
{
	if (!isDead())
	{
		processHunger(ticks, stats);
		
		// Process the goal if one is set, or set a new one if not.
		if (goal != nullptr && !goal->isFinished())
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

void Ant::moveToNode(const Node& node)
{
	kb.lastNodePassed = const_cast<Node*>(&node);
	setPosition(node.getPixelX(), node.getPixelY());
}

Node* Ant::getLastKnownFoodPosition() const
{
	return kb.lastKnownFoodPosition;
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
	stats.isDead = true;
}

Node* Ant::getNode() const
{
	return kb.lastNodePassed;
}



void Ant::onDirectGuiEvent(const sf::Event& e)
{
	// TODO: replace this with correct functionality.
	std::cout << "Ant event" << std::endl;
}


////// Private methods //////

void Ant::processHunger(long ticks, AntStats& stats)
{
	if (ticks >= stats.nextHungerIncrease)
	{
		if (stats.hunger >= stats.maxHunger)
		{
			stats.isDead = true;
		}
		else
		{
			++stats.hunger;
			stats.nextHungerIncrease += stats.hungerIncreaseRate;
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
		return move(newGoal);
	}

	// The chance that the ant will explore rather than forage, from 1 to 10.
	const int exploreChance = 2;
	int decision = random.getInteger(1, 10);
	if (decision <= exploreChance)
	{
		auto newGoal = unique_ptr<AntExplore>(new AntExplore());
		return move(newGoal);
	}
	else
	{
		auto newGoal = unique_ptr<AntForage>(new AntForage());
		return move(newGoal);
	}
}


////// Struct constructors //////

Ant::AntKnowledgeBase::AntKnowledgeBase(AntHome& home, NavGraphHelper& graphHelper) :
	home(home),
	navGraphHelper(graphHelper),
	lastKnownFoodPosition(nullptr),
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
	movementSpeed(0.5f)
{
}