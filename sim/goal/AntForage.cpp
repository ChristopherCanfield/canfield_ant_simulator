#include "AntForage.hpp"
#include "../worldobject/AntHome.hpp"
#include "../worldobject/AntFoodPile.hpp"
#include "../sim/nav/Node.hpp"

#include <cassert>

// Christopher D. Canfield
// November 2013
// AntForage.cpp

using cdc::AntForage;
using cdc::Ant;
using cdc::AntPercept;
using cdc::AntHome;
using cdc::AntFoodPile;
using cdc::Node;


AntForage::AntForage() :
	currentSubgoal(&antFindFoodSubgoal),
	AntGoal("AntForage")
{
}


AntForage::~AntForage()
{
}

void AntForage::update(Ant& ant, uint ticks, AntPercept& percept)
{
	if (!currentSubgoal->isFinished())
	{
		currentSubgoal->update(ant, ticks, percept);
	}
	else
	{
		// If food was found, pick it up.
		if (currentSubgoal == &antFindFoodSubgoal)
		{
			auto& foodPileNode = ant.getNode();
			if (foodPileNode.getAntFoodPile() != nullptr)
			{
				auto& foodPile = *foodPileNode.getAntFoodPile();
				// If the food pile has food available, take one and pick it up.
				if (foodPile.takeFood())
				{
					ant.stats.isHoldingFood = true;
					ant.kb.lastKnownFoodPosition.push_front(&foodPileNode);
				}
			}
			// Bring the food home.
			currentSubgoal = &antGoHomeSubgoal;
		}
		else if (currentSubgoal == &antGoHomeSubgoal)
		{
			// If the ant is holding food, add it to the anthill's store.
			if (ant.stats.isHoldingFood)
			{
				auto& anthill = ant.kb.home;
				anthill.addFood();
				ant.stats.isHoldingFood = false;
				ant.switchToDefaultSprite(ant.antWithFoodSprite.getPosition(), ant.antWithFoodSprite.getRotation());
			}
			setFinished(true);
		}
	}
}

void AntForage::drawPath(sf::RenderTarget& target, sf::RenderStates states, const Node& lastNodePassed) const
{
	if (currentSubgoal != nullptr)
	{
		currentSubgoal->drawPath(target, states, lastNodePassed);
	}
}

std::string AntForage::toString() const
{
	if (currentSubgoal != nullptr)
	{
		return AntGoal::toString() + " | Subgoal: " + currentSubgoal->toString();
	}
	else
	{
		return AntGoal::toString();
	}
}