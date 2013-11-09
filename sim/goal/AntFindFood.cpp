#include "AntFindFood.hpp"


// Christopher D. Canfield
// November 2013
// AntFindFood.cpp

using cdc::AntFindFood;
using cdc::Ant;
using cdc::AntPercept;


AntFindFood::AntFindFood()
{
}


AntFindFood::~AntFindFood()
{
}


void AntFindFood::update(Ant& agent, uint ticks, AntPercept& percept)
{
	// 1. Check last known food location.
	// 2. If pheromone is found at any time, follow that trail.
	// 3. Otherwise, search randomly until food is found.
}