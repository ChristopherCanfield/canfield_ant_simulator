#include "Edge.hpp"
#include "Node.hpp"

using cdc::Edge;
using cdc::Node;


Edge::Edge() :
	node(nullptr), cost(999999)
{
}

Edge::Edge(Node& node, uint cost) :
	node(&node), cost(cost)
{
}

void Edge::set(Node& node, uint cost)
{
	this->node = &node;
	this->cost = cost;
}

Node* Edge::getNode() const
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