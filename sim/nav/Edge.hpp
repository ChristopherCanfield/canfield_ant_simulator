#pragma once

// Christopher D. Canfield
// October 2013
// Edge.hpp

#include "../util/Typedefs.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


namespace cdc 
{
	class Node;
	class PathNode;

	// An edge between nodes in the graph.
	class Edge :
			public sf::Drawable
	{
	public:
		explicit Edge(Node& startNode);
		Edge(Node& startNode, Node& endNode, float cost);
		Edge(Node& startNode, Node& endNode, int cost);

		// Returns the the first node that the edge is connected to.
		Node* getNode1() const;

		// Returns the second node that the edge is connected to, or nullptr if there
		// is no connected node.
		Node* getNode2() const;

		// Returns the node opposite the specified node, or nullptr if 
		// none exists.
		Node* getOppositeNode(const Node& node) const;
		Node* getOppositeNode(PathNode node) const;

		// Returns the cost of moving along the edge.
		float getCost() const;

		uint getPheromone() const;
		void increasePheromone();
		void increasePheromoneToMax();
		void decreasePheromone();
		void setPheromoneNextNode(Node& node, uint ticks);
		Node* getPheromoneNextNode() const;
		uint getPheromoneNextNodeTickTime() const;

		bool operator==(const Edge& other) const;
		bool operator!=(const Edge& other) const;

		void update(uint ticks);

		void drawPheromone(sf::RenderTarget& target, sf::RenderStates states);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void draw(sf::RenderTarget &target, sf::RenderStates states, sf::Color color) const;

	private:
		void Edge::setVertices(Node& startNode, Node& endNode);

		// The start node.
		Node* startNode;
		// The end node, or nullptr if no node is connected to the other edge
		Node* endNode;

		// The cost of moving along the edge.
		float cost;

		// The graphical representation of the edge.
		sf::VertexArray vertices;
		// TODO: Implement this as a triangle if time permits.
		//sf::RectangleShape pheromoneVertices;
		sf::VertexArray pheromoneStrongVertices;
		sf::VertexArray pheromoneMediumVertices;
		sf::VertexArray pheromoneWeakVertices;
		// Ant pheromone, which ants use to create paths leading from home to food.
		// Pheromones are put onto edges.
		class Pheromone
		{
		public:
			Pheromone();
			~Pheromone();

			// Increases the strength of the pheromone.
			void increase();
			void increaseToMax();
			// Decreases the strength of the pheromone.
			void decrease();

			// Gets the strength of the pheromone.
			uint getStrength() const;

			// Sets the next node in the path leading from home to food.
			void setNextNode(Node& node, uint ticks);
			// Gets the next node in the path leading from home to food.
			Node* getNextNode() const;
			uint getNextNodeTickTime() const;

		private:
			// The strength of the pheromone.
			uint strength;
			// The next node in the path leading from home to food.
			Node* nextNode;

			uint nextNodeTickTime;
		};

		Pheromone pheromone;

		// The time of the next pheromone reduction, in ticks.
		uint nextPheromoneReduction;
	};
}