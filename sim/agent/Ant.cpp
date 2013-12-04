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
#include "../knowledge/Percept.hpp"
#include "../knowledge/AntPercept.hpp"

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


sf::Texture* Ant::texture = nullptr;
sf::Texture* Ant::textureWithFood = nullptr;


Ant::Ant(GuiEventManager& manager, AntHome& home, NavGraphHelper& graphHelper, const Node& startNode) :
		Button(manager),
		kb(home, graphHelper),
		selected(false)
{
	if (Ant::texture == nullptr)
	{
		Ant::texture = new sf::Texture;
		Ant::textureWithFood = new sf::Texture;

		if (!Ant::texture->loadFromFile("res/ant.png"))
		{
			std::cout << "Unable to load ant image: res/ant.png" << std::endl;
		}
		if (!Ant::textureWithFood->loadFromFile("res/ant - holding food.png"))
		{
			std::cout << "Unable to load ant image: res/ant - holding food.png" << std::endl;
		}
	}

	auto antSprite = make_unique<sf::Sprite>(*Ant::texture);	
	antSprite->setColor(sf::Color::Black);
	setDefaultImage(std::move(antSprite));
	setOriginToCenter();

	deadAntSprite.setTexture(*Ant::texture, true);
	deadAntSprite.setOrigin(deadAntSprite.getGlobalBounds().width / 1.9f, deadAntSprite.getGlobalBounds().height / 1.9f);
	deadAntSprite.setColor(sf::Color(128, 128, 128));

	antWithFoodSprite.setTexture(*Ant::textureWithFood, true);
	antWithFoodSprite.setOrigin(antWithFoodSprite.getGlobalBounds().width / 1.9f, antWithFoodSprite.getGlobalBounds().height / 1.9f);

	selectedAntSprite.setTexture(*Ant::texture, true);
	selectedAntSprite.setOrigin(selectedAntSprite.getGlobalBounds().width / 1.9f, selectedAntSprite.getGlobalBounds().height / 1.9f);
	selectedAntSprite.setColor(sf::Color(255, 106, 0));

	// Ants don't need to know about mouse move events.
	manager.removeMouseMoveListener(*this);
	manager.addDirectMouseMoveListener(*this);

	// Subscribe to indirect click events.
	manager.addClickListener(*this);

	goal = make_unique<AntForage>();
	setPositionToNode(startNode);
}

Ant::Ant(Ant&& other) :
	Button(move(other)),
	kb(move(other.kb)),
	stats(move(other.stats)),
	goal(move(other.goal)),
	selected(other.selected),
	deadAntSprite(move(other.deadAntSprite)),
	selectedAntSprite(move(other.selectedAntSprite))
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
		updateSpritePositions();

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
	setPosition(node.getPixelX<int>(), node.getPixelY<int>());
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

bool Ant::isSelected() const
{
	return selected;
}

Node& Ant::getNode() const
{
	return *kb.lastNodePassed;
}


void Ant::onDirectGuiEvent(const sf::Event& e)
{
	if (e.type == sf::Event::MouseButtonReleased && !isSelected())
	{
		selected = true;
		selectedTimer.restart();
		cout << "Ant " << getObserverId().toString() << " selected" << endl;
		cout << "  Hunger: " << stats.hunger << "% | " << (!isDead() ? "Is Alive" : "Is Dead") << endl;
		cout << "  Current Goal: " << goal->toString() << endl;

		if (!isDead())
		{
			setCurrentImage(selectedAntSprite);
		}
	}
}

void Ant::onGuiEvent(const sf::Event& e)
{
	if (e.type == sf::Event::MouseButtonReleased && isSelected() && selectedTimer.getElapsedTime().asMilliseconds() > 300)
	{
		selected = false;

		if (!isDead())
		{
			if (!stats.isHoldingFood)
			{
				switchToDefaultImage(deadAntSprite.getPosition(), deadAntSprite.getRotation());
			}
			else
			{
				setCurrentImage(antWithFoodSprite);
			}
		}
	}
}

void Ant::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (isSelected() && goal != nullptr)
	{
		drawPath(target, states);
	}

	Button::draw(target, states);
}

void Ant::drawPath(sf::RenderTarget &target, sf::RenderStates states) const
{
	goal->drawPath(target, states, this->getNode());
}


////// Private & protected methods //////

void Ant::onDeath()
{
	if (!stats.isDead)
	{
		if (isSelected()) cout << "  Ant " << getObserverId().toString() << " has died" << endl;
		stats.isDead = true;
		deadAntSprite.setPosition(getPosition());
		deadAntSprite.setRotation(getRotation());
		setCurrentImage(deadAntSprite);
	}
}

void Ant::onPickUpFood()
{
	stats.isHoldingFood = true;
	updateSpritePositions();
	if (!isSelected())
	{
		setCurrentImage(antWithFoodSprite);
	}
}

void Ant::updateSpritePositions()
{
	if (stats.isHoldingFood)
	{
		antWithFoodSprite.setPosition(getPosition());
		antWithFoodSprite.setRotation(getRotation());
	}
	if (isSelected())
	{
		selectedAntSprite.setPosition(getPosition());
		selectedAntSprite.setRotation(getRotation());
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
			if (isSelected()) cout << "  Hunger: " << stats.hunger << "%" << endl;
			// Modify the hunger increase rate by between 0.65 and 1.35, to 
			// differentiate the behaviors of the ants.
			float modifier = random.getInteger(65, 135) / 100.f;
			stats.nextHungerIncrease += static_cast<uint>(stats.hungerIncreaseRate * modifier);
		}
	}
}

void Ant::setAntWithFoodSpritePosition(float x, float y, float rotation)
{
	antWithFoodSprite.setPosition(x, y);
	antWithFoodSprite.setRotation(rotation);
}

unique_ptr<AntGoal> Ant::getNewGoal(AntStats& stats)
{
	using std::move;
	// Higher = hungrier when the ant starts looking for food to eat.
	const uint hungry = 60;

	// Look for food if hungry. This takes priority over other potential goals.
	if (stats.hunger > hungry)
	{
		auto newGoal = unique_ptr<AntEat>(new AntEat());
		if (isSelected()) cout << "  Goal changed: " << newGoal->toString() << endl;
		return move(newGoal);
	}

	// The chance that the ant will explore rather than forage, from 1 to 100.
	const int exploreChance = 1;
	int decision = random.getInteger(1, 100);
	if (decision <= exploreChance)
	{
		auto newGoal = unique_ptr<AntExplore>(new AntExplore());
		if (isSelected()) cout << "  Goal changed: " << newGoal->toString() << endl;
		return move(newGoal);
	}
	else
	{
		auto newGoal = unique_ptr<AntForage>(new AntForage());
		if (isSelected()) cout << "  Goal changed: " << newGoal->toString() << endl;
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
	hungerIncreaseRate(180),	// default ticks per second is 60, so this gives a rate of 3 seconds per increase in hunger.
	hunger(0),
	nextHungerIncrease(hungerIncreaseRate),
	maxHunger(100),
	isHoldingFood(false),
	isDead(false),
	movementSpeed(3.5f)
{
}