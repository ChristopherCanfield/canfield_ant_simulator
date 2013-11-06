#include "Edge.hpp"
#include "Node.hpp"
#include "PathNode.hpp"
#include "../util/Vector2fAdapter.hpp"

// Christopher D. Canfield
// October 2013
// Edge.cpp

using cdc::Edge;
using cdc::Node;
using cdc::PathNode;


Edge::Edge(cdc::Node& startNode) :
	startNode(&startNode),
	endNode(nullptr), 
	cost(999999),
	pheromoneLevel(0)
{
	vertices.setPrimitiveType(sf::Lines);
}

Edge::Edge(cdc::Node& startNode, cdc::Node& endNode, uint cost) :
	startNode(&startNode),
	endNode(&endNode), 
	cost(cost),
	pheromoneLevel(0)
{
	vertices.setPrimitiveType(sf::Lines);

	vertices.append(sf::Vertex(
			Vector2fAdapter(startNode.getPixelX(), startNode.getPixelY()), 
			sf::Color(0, 0, 255)));

	vertices.append(sf::Vertex(
			Vector2fAdapter(endNode.getPixelX(), endNode.getPixelY()), 
			sf::Color(0, 0, 255)));
}

void Edge::set(cdc::Node& endNode, uint cost)
{
	this->endNode = &endNode;
	this->cost = cost;

	if (vertices.getVertexCount() > 0) vertices.clear();

	vertices.append(sf::Vertex(
			Vector2fAdapter(startNode->getPixelX(), startNode->getPixelY()), 
			sf::Color(0, 0, 255)));

	vertices.append(sf::Vertex(
			Vector2fAdapter(endNode.getPixelX(), endNode.getPixelY()), 
			sf::Color(0, 0, 255)));
}

Node* Edge::getNode1() const
{
	return startNode;
}

Node* Edge::getNode2() const
{
	return endNode;
}

Node* Edge::getOppositeNode(const Node& node) const
{
	if (*startNode == node)
	{
		return endNode;
	}
	else if (*endNode == node)
	{
		return startNode;
	}
	return nullptr;
}

Node* Edge::getOppositeNode(PathNode node) const
{
	return getOppositeNode(node.getNode());
}

uint Edge::getCost() const
{
	return cost;
}

uint Edge::getPheromone() const
{
	return pheromoneLevel;
}

void Edge::increasePheromone()
{
	const uint max = 10u;
	if (pheromoneLevel < max)
	{
		++pheromoneLevel;
	}
}

void Edge::decreasePheromone()
{
	const uint min = 0u;
	if (pheromoneLevel > min)
	{
		--pheromoneLevel;
	}
}

void Edge::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (endNode != nullptr)
	{
		target.draw(vertices, states);
	}
}

bool Edge::operator==(const Edge& other) const
{
	return (this->getCost() == other.getCost() &&
			this->getNode1() == other.getNode1() &&
			this->getNode2() == other.getNode2() &&
			this->getPheromone() == other.getPheromone());
}

bool Edge::operator!=(const Edge& other) const
{
	return !(*this == other);
}