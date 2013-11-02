#include "Search.hpp"
#include "PathKey.hpp"

#include <cmath>
#include <algorithm>

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
	std::vector<Node*> frontier;
	std::unordered_set<Node*> searched;


	return std::queue<Node*>();
}

// TODO (2013-10-30): Test this.
Node* cdc::Search::findLowestCost(const Node& startNode, const Node& endNode, const std::vector<PathNode>& frontier)
{
	Node* lowestCostNode = nullptr;
	uint lowestCost = 99999u;

	for (auto node : frontier)
	{
		auto distance = straightLineHeuristic(startNode, endNode);
		for (auto edge : node.getEdgeList())
		{
			if ((distance + edge->getCost()) < lowestCost)
			{
				lowestCost = distance + edge->getCost();
				lowestCostNode = &node.getNode();
				break;
			}
		}
	}

	return lowestCostNode;
}

void cdc::Search::expandFrontier(const Node* lowestCostNode, std::vector<PathNode>& frontier, std::unordered_set<Node*>& searched)
{
	// TODO (2013-10-30): implement this.
	for (auto edge : lowestCostNode->getEdgeList())
	{
		Node* node = edge->getOppositeNode(*lowestCostNode);
		if (node != nullptr)
		{
			auto c = std::find(searched.begin(), searched.end(), node);
			//auto c = closed.find(lowestCostNode);
		}
	}
}
