#include "Edge.hpp"
#include "GridNode.hpp"


Edge::Edge() :
	node(nullptr), cost(999999)
{
}

Edge::Edge(GridNode& node, uint cost) :
	node(&node), cost(cost)
{
}

void Edge::set(GridNode& node, uint cost)
{
	this->node = &node;
	this->cost = cost;
}

GridNode* Edge::getNode() const
{
	return node;
}

uint Edge::getCost() const
{
	return cost;
}

bool Edge::isEmpty() const
{
	return (node == nullptr);
}