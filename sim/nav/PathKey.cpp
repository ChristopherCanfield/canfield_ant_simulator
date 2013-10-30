#include "PathKey.hpp"

using cdc::PathKey;
using cdc::Node;


PathKey::PathKey(const Node& startNode, const Node& endNode) :
	startNode(startNode),
	endNode(endNode)
{
}

const Node& PathKey::getStartNode() const
{
	return startNode;
}

const Node& PathKey::getEndNode() const
{
	return endNode;
}

bool PathKey::operator==(const PathKey& other) const
{
	return (startNode.getColumn() == other.startNode.getColumn() &&
			startNode.getRow() == other.startNode.getRow() &&
			endNode.getColumn() == other.endNode.getColumn() &&
			endNode.getRow() == other.endNode.getRow());
}