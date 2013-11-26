#include "AntEat.hpp"
#include "../worldobject/AntHome.hpp"
#include "../nav/Node.hpp"
#include "../worldobject/AntFoodPile.hpp"

#include <cassert>


// Christopher D. Canfield
// November 2013
// AntEat.cpp

using cdc::AntEat;
using cdc::Ant;
using cdc::AntPercept;
using cdc::AntHome;
using cdc::Node;
using cdc::AntFoodPile;


AntEat::AntEat() :
	currentSubgoal(&antFindFoodSubgoal),
	AntGoal("AntEat")
{
}


AntEat::~AntEat()
{
}


void AntEat::update(Ant& ant, uint ticks, AntPercept& percept)
{
	if (!currentSubgoal->isFinished())
	{
		currentSubgoal->update(ant, ticks, percept);
	}
	else
	{
		// Reached home, so attempt to get food there.
		if (currentSubgoal == &antGoHomeSubgoal)
		{
			auto& home = ant.getHome();
			// Take food from anthill if available, and eat it.
			if (home.takeFood())
			{
				ant.stats.hunger = 0;
				setFinished(true);
			}
			else
			{
				// If no food is available in the anthill, change the subgoal 
				// to Find Food.
				currentSubgoal = &antFindFoodSubgoal;
			}
			
		}

		// Found food outside of home.
		else if (currentSubgoal == &antFindFoodSubgoal)
		{
			auto& foodPileNode = ant.getNode();
				
			if (foodPileNode.getAntFoodPile() != nullptr)
			{
				auto& foodPile = *foodPileNode.getAntFoodPile();
				// If the food pile has food available, take one and eat it.
				if (foodPile.takeFood())
				{
					ant.stats.hunger = 0;
					ant.kb.lastKnownFoodPosition = &foodPileNode;
				}
			}
			setFinished(true);
		}
	}
}
