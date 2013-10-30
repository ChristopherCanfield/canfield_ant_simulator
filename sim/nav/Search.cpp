#include "Search.hpp"
#include "PathKey.hpp"

#include <cmath>

// Christopher D. Canfield
// October 2013
// Search.cpp


using cdc::Node;
using cdc::PathKey;

static std::unordered_map<PathKey, std::queue<Node*>> paths;


uint cdc::Search::manhattanHeuristic(Node& startNode, Node& endNode)
{
	int rowDiff = std::abs(static_cast<int>(startNode.getRow()) - static_cast<int>(endNode.getRow()));
	int columnDiff = std::abs(static_cast<int>(startNode.getColumn()) - static_cast<int>(endNode.getColumn()));

	return (rowDiff + columnDiff);
}


std::queue<Node*> cdc::Search::aStar(const Node& startNode, const Node& endNode, std::vector<Node>& navGraph)
{
	// TODO (2013-10-30): implement this.
	return std::queue<Node*>();
}
