#include "PathNode.hpp"


// Christopher D. Canfield
// October 2013
// PathNode.cpp

using cdc::PathNode;
using cdc::Node;
using cdc::Edge;


PathNode::PathNode(Node& node, uint cost) :
		node(node),
		cost(cost)
{
}

const std::vector<Edge*> PathNode::getEdgeList() const
{
	return node.getEdgeList();
}

Node& PathNode::getNode() const
{
	return node;
}

uint PathNode::getCost() const
{
	return cost;
}


bool PathNode::operator==(const PathNode& other) const
{
	return (other.getNode().getColumn() == getNode().getColumn() &&
			other.getNode().getRow() == getNode().getRow());
}


bool PathNode::operator==(const Node& other) const
{
	return (other.getColumn() == getNode().getColumn() &&
			other.getRow() == getNode().getRow());
}