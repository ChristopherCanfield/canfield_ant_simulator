#include "World.hpp"


using cdc::World;
using cdc::Node;
using cdc::Ant;
using cdc::Spider;
using cdc::AntFood;
using cdc::AntFoodPile;


World::~World()
{
}


std::vector<Node>& World::getNavGraph()
{
	return navGraph;
}

std::vector<Ant>& World::getAnts()
{
	return ants;
}

std::vector<Spider>& World::getSpiders()
{
	return spiders;
}

std::vector<sf::Sprite> World::getObstructions()
{
	return obstructions;
}

std::vector<AntFood> World::getAntFood()
{
	return antFood;
}

std::vector<AntFoodPile> World::getAntFoodPiles()
{
	return antFoodPiles;
}