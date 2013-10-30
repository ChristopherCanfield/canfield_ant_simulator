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

uint cdc::Search::straightLineHeuristic(Node& startNode, Node& endNode)
{
	float startRow = static_cast<float>(startNode.getRow());
	float endRow = static_cast<float>(endNode.getRow());
	float startColumn = static_cast<float>(startNode.getColumn());
	float endColumn = static_cast<float>(endNode.getColumn());

	float rowSquared = (startRow - endRow) * (startRow - endRow);
	float columnSquared = (startColumn - endColumn) * (startColumn - endColumn);

	//float rowSqrt = std::sqrt(rowSquared + columnSquared);
	//float columnSqrt = std::sqrt(columnSquared);

	//float rowDiff = std::sqrt(std::abs((static_cast<float>(startNode.getRow() * startNode.getRow())) - 
	//		static_cast<float>(endNode.getRow() * endNode.getRow())));
	//float columnDiff = std::sqrt(std::abs((static_cast<float>(startNode.getColumn() * startNode.getColumn())) - 
	//		static_cast<int>(endNode.getColumn())));

	return static_cast<uint>(std::sqrt(rowSquared + columnSquared));
}


std::queue<Node*> cdc::Search::aStar(const Node& startNode, const Node& endNode, std::vector<Node>& navGraph)
{
	// TODO (2013-10-30): implement this.
	return std::queue<Node*>();
}
