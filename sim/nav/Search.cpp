#include "Search.hpp"
#include "PathKey.hpp"

#include <cmath>

// Christopher D. Canfield
// October 2013
// Search.cpp


using cdc::Node;
using cdc::PathKey;

static std::unordered_map<PathKey, std::queue<Node*>> paths;


uint cdc::Search::manhattanHeuristic(const Node& startNode, const Node& endNode)
{
	int rowDiff = std::abs(static_cast<int>(startNode.getRow()) - static_cast<int>(endNode.getRow()));
	int columnDiff = std::abs(static_cast<int>(startNode.getColumn()) - static_cast<int>(endNode.getColumn()));

	return (rowDiff + columnDiff);
}

uint cdc::Search::straightLineHeuristic(const Node& startNode, const Node& endNode)
{
	float startRow = static_cast<float>(startNode.getRow());
	float endRow = static_cast<float>(endNode.getRow());
	float startColumn = static_cast<float>(startNode.getColumn());
	float endColumn = static_cast<float>(endNode.getColumn());

	float rowSquared = (startRow - endRow) * (startRow - endRow);
	float columnSquared = (startColumn - endColumn) * (startColumn - endColumn);

	return static_cast<uint>(std::sqrt(rowSquared + columnSquared));
}


std::queue<Node*> cdc::Search::aStar(const Node& startNode, const Node& endNode, const std::vector<Node>& navGraph)
{
	// TODO (2013-10-30): implement this.
	return std::queue<Node*>();
}

// TODO (2013-10-30): Test this.
Node* cdc::Search::findLowestCost(const Node& startNode, const Node& endNode, const std::list<Node*>& frontier)
{
	Node* lowestCostNode = nullptr;
	uint lowestCost = 99999u;

	for (auto node : frontier)
	{
		auto distance = straightLineHeuristic(startNode, endNode);
		for (auto edge : node->getEdgeList())
		{
			if ((distance + edge->getCost()) < lowestCost)
			{
				lowestCost = distance + edge->getCost();
				lowestCostNode = node;
				break;
			}
		}
	}

	return lowestCostNode;
}

void cdc::Search::expandFrontier(std::list<Node*>& frontier)
{
	// TODO (2013-10-30): implement this.
}
