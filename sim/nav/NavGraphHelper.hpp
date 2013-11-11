#pragma once

#include "Node.hpp"
#include "GridLocation.hpp"
#include "../util/Typedefs.hpp"

#include <vector>
#include <unordered_map>
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

		// Returns the node at the specified location, or nullptr if no node 
		// is found.
		Node* getNode(GridLocation location);

	private:
		std::vector<std::unique_ptr<Node>>* navGraph;
		std::unordered_map<GridLocation, Node*> nodes;
		uint maxRow;
		uint maxColumn;
	};
}