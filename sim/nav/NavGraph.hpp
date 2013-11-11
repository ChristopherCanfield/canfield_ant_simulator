#pragma once

#include "Node.hpp"
#include "GridLocation.hpp"

#include <vector>
#include <memory>

// Christopher D. Canfield
// November 2013
// NavGraph.hpp



namespace cdc
{

	class NavGraph
	{
	public:
		// Constructs the nav graph using the graph parameter.
		explicit NavGraph(std::vector<std::unique_ptr<Node>>&& graph);
		~NavGraph();
		
		// Returns true if the node location is valid, or false if not.
		bool isValid(GridLocation nodeLocation);

	private:
		std::vector<std::unique_ptr<Node>> navGraph;
	};
}