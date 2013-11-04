#include "Search.hpp"
#include "PathKey.hpp"

#include <cmath>
#include <algorithm>
#include <iostream>

// Christopher D. Canfield
// October 2013
// Search.cpp


using cdc::Node;
using cdc::PathKey;
using cdc::PathNode;

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


// Comparator for A* priority queue.
class PathNodeComparison
{
public:
	bool operator()(PathNode& node1, PathNode& node2)
	{
		return (node1.getCost() > node2.getCost());
	}
};

std::queue<Node*> cdc::Search::aStar(const Node& startNode, const Node& endNode, const std::vector<Node>& navGraph,
									 uint (*heuristic)(const Node& startNode, const Node& endNode), bool debug)
{
	using namespace std;

	priority_queue<PathNode, vector<PathNode>, PathNodeComparison> frontier;
	PathNode firstNode(startNode, 0);
	if (debug) cout << "start node: " << startNode.getRow() << "," << startNode.getColumn() << endl;
	if (debug) cout << "end node: " << endNode.getRow() << "," << endNode.getColumn() << endl;

	queue<Node*> path;
	std::unordered_set<Node*> searched;

	searched.insert(&const_cast<Node&>(startNode));
	frontier.push(firstNode);

	while (!frontier.empty())
	{
		// Get lowest cost node.
		auto lowestCost = frontier.top();
		frontier.pop();
		if (debug) cout << "popped from frontier: " << lowestCost.getNode().getRow() 
				<< "," << lowestCost.getNode().getColumn() << endl;

		path.push(&lowestCost.getNode());
		
		// Return the path if the goal has been reached.
		if (lowestCost.getNode() == endNode)
		{
			if (debug) cout << "reached end node; returning" << endl;
			return path;
		}

		auto edges = lowestCost.getEdgeList();
		for (auto& edge : edges)
		{
			auto currentNode = edge->getOppositeNode(lowestCost);
			if (debug) cout << "current node: " << currentNode->getRow() << "," 
					<< currentNode->getColumn() << endl;

			// Calculate the cost for traversing this edge.
			uint h = heuristic(*currentNode, endNode);
			uint g = edge->getCost();
			uint cost = h + g;
			if (debug) cout << "  current node cost: " << cost << endl;

			// Determine if this node has already been traversed.
			auto foundNode = find(searched.begin(), searched.end(), currentNode);
			bool notFound = (foundNode == searched.end());
			// If it does not already exist, add it to the frontier.
			if (notFound)
			{
				frontier.push(PathNode(*currentNode, cost));
				searched.insert(currentNode);

				if (debug) cout << "adding to frontier: " << currentNode->getRow() << "," 
					<< currentNode->getColumn() << endl;

				// TODO (2013-11-02): What happens if a better way is found 
				// to a node? 
			}
		}
	}

	return path;
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
