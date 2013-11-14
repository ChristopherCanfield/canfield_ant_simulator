#include "Edge.hpp"
#include "Node.hpp"

// Christopher D. Canfield
// November 2013
// Pheromone.cpp


using cdc::Node;
using cdc::Edge;



Edge::Pheromone::Pheromone() :
	nextNode(nullptr),
	strength(0u)
{
}


Edge::Pheromone::~Pheromone()
{
}


void Edge::Pheromone::increase()
{
	const uint max = 10u;
	if (strength < max)
	{
		++strength;
	}
}

void Edge::Pheromone::decrease()
{
	const uint min = 0u;
	if (strength > min)
	{
		--strength;
	}
}

uint Edge::Pheromone::getStrength() const
{
	return strength;
}

void Edge::Pheromone::setNextNode(Node& node)
{
	nextNode = &node;
}

Node* Edge::Pheromone::getNextNode() const
{
	return nextNode;
}