#pragma once

#include "Node.hpp"
#include "GridLocation.hpp"
#include "../util/Typedefs.hpp"

#include <vector>
#include <memory>

// Christopher D. Canfield
// November 2013
// NavGraphHelper.hpp



namespace cdc
{
	// Provides helper functions for working with the navigation graph, but
	// does not actually own the graph.
	class NavGraphHelper
	{
	public:
		NavGraphHelper();
		// Constructs the nav graph using the graph parameter, which is a non-owning
		// reference to the navigation graph vector.
		explicit NavGraphHelper(std::vector<std::unique_ptr<Node>>& graph);
		~NavGraphHelper();
		
		// Returns true if the node location is valid, or false if not.
		bool isValid(GridLocation nodeLocation) const;

		uint getMaxRow() const;
		uint getMaxColumn() const;

	private:
		std::vector<std::unique_ptr<Node>>* navGraph;
		uint maxRow;
		uint maxColumn;
	};
}