#include "PathNode.hpp"


// Christopher D. Canfield
// October 2013
// PathNode.cpp

using cdc::PathNode;
using cdc::Node;
using cdc::Edge;


PathNode::PathNode(const Node& node, float g, float h) :
		node(const_cast<Node*>(&node)),
		gCost(g),
		hCost(h),
		parent(nullptr)
{
}

PathNode::PathNode(const Node& node, PathNode& parent, float g, float h) :
		node(const_cast<Node*>(&node)),
		gCost(g),
		hCost(h),
		parent(&parent)
{
}

PathNode::PathNode(const Node& node, PathNode& parent, int g, int h) :
		node(const_cast<Node*>(&node)),
		gCost(static_cast<float>(g)),
		hCost(static_cast<float>(h)),
		parent(&parent)
{
}

PathNode::PathNode(const PathNode& pathNode) :
		node(pathNode.node),
		gCost(pathNode.gCost),
		hCost(pathNode.hCost),
		parent(pathNode.parent)
{
}

PathNode& PathNode::operator=(const PathNode& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	this->node = rhs.node;
	this->gCost = rhs.gCost;
	this->hCost = rhs.hCost;
	this->parent = rhs.parent;
	return *this;
}

const std::vector<std::shared_ptr<Edge>> PathNode::getEdgeList() const
{
	return node->getEdgeList();
}

Node& PathNode::getNode() const
{
	return *node;
}

PathNode* PathNode::getParent() const
{
	return parent;
}

void PathNode::setParent(PathNode& parent)
{
	this->parent = &parent;
}

float PathNode::getG() const
{
	return gCost;
}

float PathNode::getH() const
{
	return hCost;
}

float PathNode::getCost() const
{
	return gCost + hCost;
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