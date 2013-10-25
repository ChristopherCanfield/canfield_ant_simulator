#pragma once

// Christopher D. Canfield
// October 2013
// Edge.hpp

namespace cdc 
{ 
	class Node;
}

#include "../util/Typedefs.hpp"

#include <SFML/Graphics.hpp>


namespace cdc 
{
	// An edge between nodes in the graph.
	class Edge :
			public sf::Drawable
	{
	public:
		Edge(cdc::Node& startNode);
		Edge(cdc::Node& startNode, cdc::Node& endNode, uint cost);

		// Sets the attached node.
		void set(cdc::Node& endNode, uint cost);

		// Removes the connected node.
		// TODO: remove this if it remains unused.
		//void removeConnectedNode();

		// Returns the starting node that the edge is connected to.
		cdc::Node* getStartNode() const;

		// Returns the ending node that the edge is connected to, or nullptr if there
		// is no connected node.
		cdc::Node* getEndNode() const;

		// Returns the cost of moving along the edge.
		uint getCost() const;
	
		// Returns true if there is no connected node. This is equivalent to the
		// following: (getNode() == nullptr)
		bool isEmpty() const;

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		// The start node.
		cdc::Node* startNode;
		// The end node, or nullptr if no node is connected to the other edge
		cdc::Node* endNode;

		// The cost of moving along the edge.
		uint cost;

		// The graphical representation of the edge.
		sf::VertexArray vertices;
	};
}