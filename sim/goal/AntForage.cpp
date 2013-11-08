#include "AntForage.hpp"
#include "../worldobject/AntHome.hpp"

#include <cassert>

// Christopher D. Canfield
// November 2013
// AntForage.cpp

using cdc::AntForage;
using cdc::Ant;
using cdc::AntPercept;
using cdc::AntHome;


AntForage::AntForage() :
	currentSubgoal(&antFindFoodSubgoal)
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
		if (currentSubgoal == &antFindFoodSubgoal)
		{
			// TODO: get the node that has the food, and take food from it.
			assert(false);
		}
		else if (currentSubgoal == &antGoHomeSubgoal)
		{
			// If the ant is holding food, add it to the anthill's store.
			if (ant.isHoldingFood)
			{
				auto& anthill = ant.kb.home;
				anthill.addFood();
			}
			setFinished(true);
		}
	}
}