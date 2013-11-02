#include "PathNode.hpp"


// Christopher D. Canfield
// October 2013
// PathNode.cpp

using cdc::PathNode;
using cdc::Node;
using cdc::Edge;


PathNode::PathNode(const Node& node, uint cost) :
		node(const_cast<Node&>(node)),
		cost(cost)
{
}

PathNode PathNode::operator=(const PathNode& rhs)
{
	return PathNode(rhs.getNode(), rhs.getCost());
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