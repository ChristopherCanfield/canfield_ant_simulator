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
		~Node();
	
		// Adds an edge.
		// - edge: the Edge to add.
		// - addEdgeToOppositeNode: add the Edge to the opposite node as well.
		//		In other words, if this is adding edge A->B, also add B->A.
		Node& addEdge(Edge& edge, bool addEdgeToOppositeNode = true);

		// Returns a reference to the edge list.
		const std::vector<Edge*>& getEdgeList() const;

		// Returns a reference to an edge.
		// - index: the edge's index in the Node's edge list.
		const Edge* getEdge(uint index) const;

		// Gets the x location of the Node, in pixels.
		int getPixelX() const;
		// Gets the y location of the Node, in pixels.
		int getPixelY() const;

		// Returns the node's row in the navigation grid.
		uint getRow() const;
		// Returns the node's column in the navigation grid.
		uint getColumn() const;

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		bool operator==(const Node& other) const;
		bool operator!=(const Node& other) const;

	private:
		void removeEdge(Edge& edge);

		std::vector<Edge*> edges;

		int pixelX;
		int pixelY;

		// The node's row-column location.
		GridLocation location;

		// The graphical representation of the node.
		sf::CircleShape circle;
	};
}


namespace std
{
	template<>
	class hash<cdc::Node>
	{
	public:
		// Adapted from Bjarne Stroustrup, "A Tour of C++"
		std::size_t operator()(const cdc::Node& key) const
		{
			return hash<uint>()(key.getColumn()) ^
					hash<uint>()(key.getRow());
		}
	};
}