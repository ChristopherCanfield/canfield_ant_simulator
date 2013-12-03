#include "World.hpp"

// Christopher D. Canfield
// November 2013
// World.cpp

using cdc::World;
using cdc::Node;
using cdc::Ant;
using cdc::Spider;
using cdc::AntFood;
using cdc::AntFoodPile;
using cdc::AntHome;
using cdc::GuiEventManager;


World::~World()
{
}

GuiEventManager& World::getGuiEventManager()
{
	return *eventManager;
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

std::vector<sf::Sprite>& World::getObstructions()
{
	return obstructions;
}

std::vector<AntFood>& World::getAntFood()
{
	return antFood;
}

std::vector<AntFoodPile>& World::getAntFoodPiles()
{
	return antFoodPiles;
}

std::vector<AntHome>& World::getAntHills()
{
	return antHills;
}