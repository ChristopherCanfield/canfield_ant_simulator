#pragma once

// Christopher D. Canfield
// October 2013
// Search.hpp

#include "../util/Typedefs.hpp"
#include "Node.hpp"


namespace cdc
{

	namespace Search
	{
		uint manhattanHeuristic(Node& startNode, Node& endNode);
	}
}