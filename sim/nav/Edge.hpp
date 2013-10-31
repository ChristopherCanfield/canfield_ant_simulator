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
		Edge(Node& startNode);
		Edge(Node& startNode, Node& endNode, uint cost);

		// Sets the attached node.
		void set(Node& endNode, uint cost);

		// Removes the connected node.
		// TODO: remove this if it remains unused.
		//void removeConnectedNode();

		// Returns the the first node that the edge is connected to.
		Node* getNode1() const;

		// Returns the second node that the edge is connected to, or nullptr if there
		// is no connected node.
		Node* getNode2() const;

		Node* getOppositeNode(const Node& node) const;

		// Returns the cost of moving along the edge.
		uint getCost() const;

		uint getPheromone() const;
		void increasePheromone();
		void decreasePheromone();

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		// The start node.
		Node* startNode;
		// The end node, or nullptr if no node is connected to the other edge
		Node* endNode;

		// The cost of moving along the edge.
		uint cost;

		uint pheromoneLevel;

		// The graphical representation of the edge.
		sf::VertexArray vertices;
	};
}