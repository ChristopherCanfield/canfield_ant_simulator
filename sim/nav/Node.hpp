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
#include <functional>


namespace cdc 
{
	class AntFoodPile;

	// A node in a graph.
	class Node :
		public sf::Drawable
	{
	public:
		Node(GridLocation location, int pixelX, int pixelY);
		~Node();

		Node(const Node&& other);
		Node& operator=(const Node&& other);
	
		// Adds an edge.
		// - edge: the Edge to add.
		// - addEdgeToOppositeNode: add the Edge to the opposite node as well.
		//		In other words, if this is adding edge A->B, also add B->A.
		Node& addEdge(std::shared_ptr<Edge> edge, bool addEdgeToOppositeNode = true);

		// Removes an edge.
		void removeEdge(Edge& edge, bool removeEdgeFromOpposite = true);

		// Returns a reference to the edge list.
		const std::vector<std::shared_ptr<Edge>>& getEdgeList() const;

		// Returns a reference to an edge.
		// - index: the edge's index in the Node's edge list.
		const Edge& getEdge(uint index) const;

		// Returns true if the edge exists.
		bool edgeExists(std::shared_ptr<Edge> edge) const;

		// Gets the x location of the Node, in pixels.
		int getPixelX() const;
		// Gets the y location of the Node, in pixels.
		int getPixelY() const;

		sf::Rect<float> getBoundingBox() const;

		// Returns the node's row in the navigation grid.
		uint getRow() const;
		// Returns the node's column in the navigation grid.
		uint getColumn() const;

		// Returns true if the node is connected to the navigation graph 
		// (i.e., it has at least one edge).
		bool isConnected() const;

		// Sets the ant food pile at this node.
		// - antFoodPile: A non-owning pointer to an AntFoodPile, or nullptr.
		void setAntFoodPile(AntFoodPile* antFoodPile);
		// Gets a non-owning pointer to the ant food pile at this node.
		AntFoodPile* getAntFoodPile() const;

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		bool operator==(const Node& other) const;
		bool operator!=(const Node& other) const;

	private:
		void removeEdge(Edge& edge);

		std::vector<std::shared_ptr<Edge>> edges;

		int pixelX;
		int pixelY;

		// The node's row-column location.
		GridLocation location;

		// The graphical representation of the node.
		sf::CircleShape circle;

		AntFoodPile* antFoodPile;
	};
}

std::ostream& operator<<(std::ostream& stream, const cdc::Node& node);


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