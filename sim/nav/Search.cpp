#include "Search.hpp"

#include <cmath>

// Christopher D. Canfield
// October 2013
// Search.cpp


using cdc::Node;


uint cdc::Search::manhattanHeuristic(Node& startNode, Node& endNode)
{
	int rowDiff = std::abs(static_cast<int>(startNode.getRow()) - static_cast<int>(endNode.getRow()));
	int columnDiff = std::abs(static_cast<int>(startNode.getColumn()) - static_cast<int>(endNode.getColumn()));

	return (rowDiff + columnDiff);
}