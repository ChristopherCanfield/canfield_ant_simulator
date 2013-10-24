#pragma once

// Christopher D. Canfield
// October 2013
// Edge.hpp

namespace cdc 
{ 
	class Node;
}

#include "../util/Typedefs.hpp"

namespace cdc 
{
	// An edge between nodes in the graph.
	class Edge
	{
	public:
		Edge();
		Edge(cdc::Node& node, uint cost);

		// Sets the attached node.
		void set(cdc::Node& node, uint cost);

		// Removes the connected node.
		// TODO: remove this if it remains unused.
		//void removeConnectedNode();

		// Returns the node that the edge is connected to, or nullptr if there
		// is no connected node.
		cdc::Node* getNode() const;

		// Returns the cost of moving along the edge.
		uint getCost() const;
	
		// Returns true if there is no connected node. This is equivalent to the
		// following: (getNode() == nullptr)
		bool isEmpty() const;

	private:
		// The connected node, or nullptr if no node is connected to the other edge.
		cdc::Node* node;
		// The cost of moving along the edge.
		uint cost;
	};
}