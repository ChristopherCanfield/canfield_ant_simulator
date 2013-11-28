#pragma once

// Christopher D. Canfield
// October 2013
// Search.hpp

#include "../util/Typedefs.hpp"
#include "PathKey.hpp"

#include <deque>
#include <vector>
#include <unordered_map>

namespace cdc
{
	class Node;
	class PathNode;

	class Search
	{
	public:
		// Returns the distance using a Manhattan-based (grid) calculation.
		static float manhattanHeuristic(const Node& startNode, const Node& endNode);

		// Returns the straight line distance between two nodes.
		static float straightLineHeuristic(const Node& startNode, const Node& endNode);

		// The A* search algorithm.
		// Returns a queue of Node* from startNode to endNode.
		//	- startNode: The start of the path.
		//	- endNode: The end of the path.
		//	- heuristic: A function pointer to the heuristic that should be used.
		//	- debug: Whether to print debug messages.
		static std::deque<Node*> aStar(const Node& startNode, const Node& endNode,
				float (*heuristic)(const Node& startNode, const Node& endNode), bool debug = false);

		// My original attempt at searching the graph. This does usually, but not always, return 
		// the optimal path, at least when the graph is not complex.
		static std::deque<Node*> graphSearch(const Node& startNode, const Node& endNode,
				float (*heuristic)(const Node& startNode, const Node& endNode), bool debug = false);

		static void printPath(std::deque<Node*> path);

	private:
		static std::deque<Node*> constructPath(PathNode& finalNodeInPath, Node& startNode);

		// Contains previously calculated paths from start nodes to end nodes.
		// - key: NodeMapKey made up of a start node and end node.
		// - value: queue of Node* making up the path
		static std::unordered_map<PathKey, std::deque<Node*>> paths;
	};
}