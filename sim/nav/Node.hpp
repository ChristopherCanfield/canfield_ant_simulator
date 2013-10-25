#pragma once

// Christopher D. Canfield
// October 2013
// Node.hpp

#include "Edge.hpp"
#include "GridLocation.hpp"
#include "../util/Typedefs.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>


namespace cdc 
{
	// A node in a graph.
	class Node :
		public sf::Drawable
	{
	public:
		Node(GridLocation location, int pixelX, int pixelY);
	
		// Adds an edge.
		// - edge: the Edge to add.
		Node& addEdge(std::shared_ptr<Edge> edge);

		// Returns a reference to the edge list.
		std::vector<std::shared_ptr<Edge>>& getEdgeList();

		// Returns a reference to an edge.
		// - index: the edge's index in the Node's edge list.
		std::shared_ptr<Edge> getEdge(uint index);

		// Gets the x location of the Node, in pixels.
		int getPixelX() const;
		// Gets the y location of the Node, in pixels.
		int getPixelY() const;

		// Returns the node's row in the navigation grid.
		uint getRow() const;
		// Returns the node's column in the navigation grid.
		uint getColumn() const;

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		std::vector<std::shared_ptr<Edge>> edges;

		int pixelX;
		int pixelY;

		// The node's row-column location.
		GridLocation location;

		// The graphical representation of the node.
		sf::CircleShape circle;
	};
}