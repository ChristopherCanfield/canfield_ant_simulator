#include "AntFindFood.hpp"


// Christopher D. Canfield
// November 2013
// AntFindFood.cpp

using cdc::AntFindFood;
using cdc::Ant;
using cdc::AntPercept;


AntFindFood::AntFindFood() :
	AntGoal("AntFindFood"),
	foodFound(false)
{
}


AntFindFood::~AntFindFood()
{
}


void AntFindFood::update(Ant& ant, uint ticks, AntPercept& percept)
{
	// 1. Check last known food location.
	// 2. If pheromone is found at any time, follow that trail.
	// 3. Otherwise, search randomly until food is found.
	assert(false);

	if (foodFound)
	{
		setFinished(true);
		return;
	}

	if (!goal->isFinished())
	{
		
	}
	else
	{
		setGoal(ant);
	}
}

void AntFindFood::setGoal(Ant& ant)
{
	auto lastKnowFood = ant.popLastKnownFoodPosition();
	// TODO: implement the rest of this.
}

void AntFindFood::drawPath(sf::RenderTarget& target, sf::RenderStates states) const
{
	// TODO: draw the path.
}