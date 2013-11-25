#include "AntHome.hpp"
#include "../nav/Node.hpp"

#include <cassert>

// Christopher D. Canfield
// November 2013
// AntHome.hpp

using cdc::AntHome;
using cdc::Node;


AntHome::AntHome(Node& node) :
	foodCount(0),
	node(node)
{
}


AntHome::~AntHome()
{
}


uint AntHome::getFoodCount() const
{
	return foodCount;
}

bool AntHome::takeFood()
{
	if (foodCount > 0)
	{
		--foodCount;
		return true;
	}
	else
	{
		return false;
	}
}

void AntHome::addFood()
{
	++foodCount;
}


Node& AntHome::getNode() const
{
	return node;
}

void AntHome::update(uint ticks)
{
	// TODO: generate ants based on the amount of food.
	assert(false);
}