#pragma once

// Christopher D. Canfield
// October 2013
// Node.hpp

#include "Edge.hpp"
#include "GridLocation.hpp"
#include "../util/Typedefs.hpp"

#include <vector>


namespace cdc 
{
	// A node in a graph.
	class Node
	{
	public:
		Node(GridLocation location, int pixelX, int pixelY);
	
		// Adds an edge.
		// - edge: the Edge to add.
		// - addToConnectedNode: whether to add an Edge in the reverse direction to the 
		//   newly connected node as well. If true, the same cost will be used for both
		//   directions.
		Node& addEdge(Edge edge, bool addToConnectedNode = true);

		// Returns a reference to the edge list.
		std::vector<Edge>& getEdgeList();

		// Returns a reference to an edge.
		// - index: the edge's index in the Node's edge list.
		Edge& getEdge(int index);

		// Gets the x location of the Node, in pixels.
		int getPixelX() const;
		// Gets the y location of the Node, in pixels.
		int getPixelY() const;

		// Returns the node's row in the navigation grid.
		uint getRow() const;
		// Returns the node's column in the navigation grid.
		uint getColumn() const;

	private:
		std::vector<Edge> edges;

		int pixelX;
		int pixelY;

		GridLocation location;
	};
}