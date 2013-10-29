#pragma once

// Christopher D. Canfield
// October 2013
// Search.hpp

#include "../util/Typedefs.hpp"
#include "Node.hpp"

#include <queue>
#include <vector>

namespace cdc
{

	namespace Search
	{
		uint manhattanHeuristic(Node& startNode, Node& endNode);

		std::queue<Node*> aStar(Node& startNode, Node& endNode, std::vector<Node>& navGraph);
	}
}