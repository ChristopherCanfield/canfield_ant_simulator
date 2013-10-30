#pragma once

// Christopher D. Canfield
// October 2013
// Search.hpp

#include "../util/Typedefs.hpp"
#include "Node.hpp"
#include "PathKey.hpp"

#include <queue>
#include <vector>
#include <unordered_map>

namespace cdc
{
	class Search
	{
	public:
		// Returns the distance using a Manhattan-based (grid) calculation.
		static uint manhattanHeuristic(Node& startNode, Node& endNode);

		// The A* search algorithm.
		static std::queue<Node*> aStar(const Node& startNode, const Node& endNode, std::vector<Node>& navGraph);

	private:
		// Contains previously calculated paths from start nodes to end nodes.
		// - key: NodeMapKey made up of a start node and end node.
		// - value: queue of Node* making up the path
		static std::unordered_map<PathKey, std::queue<Node*>> paths;
	};
}