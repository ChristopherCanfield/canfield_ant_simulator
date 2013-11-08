#include "AntEat.hpp"
#include "../worldobject/AntHome.hpp"

#include <cassert>


// Christopher D. Canfield
// November 2013
// AntEat.cpp

using cdc::AntEat;
using cdc::Ant;
using cdc::AntPercept;
using cdc::AntHome;


AntEat::AntEat() :
	currentSubgoal(&antFindFoodSubgoal)
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
				ant.kb.hunger = 0;
				setFinished(true);
			}
			else
			{
				// Change subgoal to find food, because there is no food available
				// in the anthill.
				currentSubgoal = &antFindFoodSubgoal;
			}
			
		}
		// Found food outside of home.
		else if (currentSubgoal == &antFindFoodSubgoal)
		{
			// TODO: get the food from the node, and eat it.
			assert(false);
		}
	}
}
