#include "Search.hpp"
#include "PathKey.hpp"
#include "Node.hpp"
#include "PathNode.hpp"

#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>

// Christopher D. Canfield
// October 2013
// Search.cpp


using cdc::Node;
using cdc::PathKey;
using cdc::PathNode;

using namespace std;

std::unordered_map<PathKey, std::deque<Node*>> cdc::Search::paths;



float cdc::Search::manhattanHeuristic(const Node& startNode, const Node& endNode)
{
	int startRow = static_cast<int>(startNode.getRow());
	int endRow = static_cast<int>(endNode.getRow());
	int startColumn = static_cast<int>(startNode.getColumn());
	int endColumn = static_cast<int>(endNode.getColumn());

	int rowDiff = std::abs(startRow - endRow);
	int columnDiff = std::abs(startColumn - endColumn);

	return (static_cast<float>(rowDiff + columnDiff));
}

float cdc::Search::straightLineHeuristic(const Node& startNode, const Node& endNode)
{
	float startRow = static_cast<float>(startNode.getRow());
	float endRow = static_cast<float>(endNode.getRow());
	float startColumn = static_cast<float>(startNode.getColumn());
	float endColumn = static_cast<float>(endNode.getColumn());

	float rowSquared = (startRow - endRow) * (startRow - endRow);
	float columnSquared = (startColumn - endColumn) * (startColumn - endColumn);

	return std::sqrt(rowSquared + columnSquared);
}


// Comparator for A* priority queue.
class PathNodeComparison
{
public:
	bool operator()(shared_ptr<PathNode> node1, shared_ptr<PathNode> node2)
	{
		return (node1->getCost() > node2->getCost());
	}
};

//std::deque<Node*> cdc::Search::graphSearch(const Node& startNode, const Node& endNode,
//									 float (*heuristic)(const Node& startNode, const Node& endNode), bool debug)
//{
//	if (debug) cout << "start node: " << startNode.getRow() << "," << startNode.getColumn() << endl;
//	if (debug) cout << "end node: " << endNode.getRow() << "," << endNode.getColumn() << endl;
//
//	// Check if the path was already computed. If it was, return it.
//	if (paths.count(PathKey(startNode, endNode)) != 0)
//	{
//		if (debug) cout << "+path found in map; returning" << endl;
//		return paths[PathKey(startNode, endNode)];
//	}
//
//	priority_queue<PathNode, vector<PathNode>, PathNodeComparison> frontier;
//	PathNode firstNode(startNode, 0, heuristic(startNode, endNode));
//
//	deque<Node*> path;
//	std::unordered_set<Node*> searched;
//
//	searched.insert(&const_cast<Node&>(startNode));
//	frontier.push(firstNode);
//
//	while (!frontier.empty())
//	{
//		// Get lowest cost node.
//		PathNode lowestCost(frontier.top());
//		frontier.pop();
//		if (debug) cout << endl << "popped from frontier: " << lowestCost.getNode().getRow() 
//				<< "," << lowestCost.getNode().getColumn() << endl;
//
//		path.push_back(&lowestCost.getNode());
//		
//		// Return the path if the goal has been reached.
//		if (lowestCost.getNode() == endNode)
//		{
//			if (debug) cout << "+reached end node; returning" << endl;
//			// Add path to map.
//			paths[PathKey(startNode, endNode)] = path;
//			return path;
//		}
//
//		auto edges = lowestCost.getEdgeList();
//		for (auto edge : edges)
//		{
//			auto currentNode = edge->getOppositeNode(lowestCost);
//			if (debug) cout << "|-searching edge: current node: " << currentNode->getRow() << "," 
//					<< currentNode->getColumn() << endl;
//
//			// Calculate the cost for traversing this edge.
//			float h = heuristic(*currentNode, endNode);
//			float g = edge->getCost();
//			float cost = h + g;
//			if (debug) cout << "|---current node cost: " << cost << endl;
//
//			// Determine if this node has already been traversed.
//			auto foundNode = find(searched.begin(), searched.end(), currentNode);
//			bool found = (foundNode != searched.end());
//			if (debug) cout << "|---found: " << found << endl;
//
//			// If it was not already searched, add it to the frontier.
//			if (!found)
//			{
//				if (debug) cout << "|---adding to frontier: " << currentNode->getRow() << "," 
//					<< currentNode->getColumn() << endl;
//
//				//auto currentPathNode = PathNode(*currentNode, lowestCost, g, h);
//				//frontier.push(currentPathNode);
//				//searched.insert(currentNode);
//			}
//		}
//	}
//
//	if (debug) cout << "-no path found; returning" << endl;
//	return path;
//}

std::deque<Node*> cdc::Search::aStar(const Node& startNode, const Node& endNode,
									 float (*heuristic)(const Node& startNode, const Node& endNode), bool debug)
{
	if (debug) cout << "start node: " << startNode.getRow() << "," << startNode.getColumn() << endl;
	if (debug) cout << "end node: " << endNode.getRow() << "," << endNode.getColumn() << endl;

	// Check if the path was already computed. If it was, return it.
	if (paths.count(PathKey(startNode, endNode)) != 0)
	{
		if (debug) cout << "+path found in map; returning" << endl;
		return paths[PathKey(startNode, endNode)];
	}

	priority_queue<shared_ptr<PathNode>, vector<shared_ptr<PathNode>>, PathNodeComparison> frontier;
	auto firstNode = make_shared<PathNode>(startNode, 0.f, heuristic(startNode, endNode));

	std::unordered_set<Node*> searched;

	searched.insert(&const_cast<Node&>(startNode));
	frontier.push(firstNode);

	while (!frontier.empty())
	{
		// Get lowest cost node.
		auto lowestCost(frontier.top());
		frontier.pop();
		if (debug) cout << endl << "popped from frontier: " << lowestCost->getNode().getRow() 
				<< "," << lowestCost->getNode().getColumn() << endl;
		
		// Return the path if the goal has been reached.
		if (lowestCost->getNode() == endNode)
		{
			if (debug) cout << "+reached end node; returning" << endl;
			// Add path to map.
			auto path = constructPath(*lowestCost, startNode);
			paths[PathKey(startNode, endNode)] = path;
			return path;
		}

		auto edges = lowestCost->getEdgeList();
		for (auto edge : edges)
		{
			auto currentNode = edge->getOppositeNode(*lowestCost);
			if (debug) cout << "|-searching edge: current node: " << currentNode->getRow() << "," 
					<< currentNode->getColumn() << endl;

			// Calculate the cost for traversing this edge.
			float h = heuristic(*currentNode, endNode);
			float g = edge->getCost() + lowestCost->getG();
			float cost = h + g;
			if (debug) cout << "|---current node cost: " << cost << endl;

			// Determine if this node has already been traversed.
			auto foundNode = find(searched.begin(), searched.end(), currentNode);
			bool found = (foundNode != searched.end());
			if (debug) cout << "|---found: " << found << endl;

			// If it was not already searched, add it to the frontier.
			if (!found)
			{
				if (debug) cout << "|---adding to frontier: " << currentNode->getRow() << "," 
					<< currentNode->getColumn() << endl;

				auto currentPathNode = make_shared<PathNode>(*currentNode, lowestCost, g, h);
				frontier.push(currentPathNode);
				searched.insert(currentNode);
			}
		}
	}

	if (debug) cout << "-no path found; returning" << endl;
	return deque<Node*>();
}

std::deque<Node*> cdc::Search::constructPath(PathNode& finalNodeInPath, const Node& startNode)
{
	deque<Node*> path;
	PathNode* currentPathNode = &finalNodeInPath;
	while (currentPathNode != nullptr && currentPathNode->getNode() != startNode)
	{
		path.push_front(&currentPathNode->getNode());
		currentPathNode = currentPathNode->getParent();
	}
	return path;
}


void cdc::Search::printPath(std::deque<Node*> path)
{
	while (!path.empty())
	{
		auto node = path.front();
		std::cout << " " << *node;
		path.pop_front();
	}
}
