#include "Edge.hpp"
#include "Node.hpp"

// Christopher D. Canfield
// October 2013
// Edge.cpp

using cdc::Edge;
using cdc::Node;


Edge::Edge(cdc::Node& startNode) :
	startNode(&startNode),
	endNode(nullptr), 
	cost(999999)
{
	vertices.setPrimitiveType(sf::Lines);
}

Edge::Edge(cdc::Node& startNode, cdc::Node& endNode, uint cost) :
	startNode(&startNode),
	endNode(&endNode), 
	cost(cost)
{
	vertices.setPrimitiveType(sf::Lines);

	vertices.append(sf::Vertex(
			sf::Vector2f(startNode.getPixelX(), startNode.getPixelY()), 
			sf::Color(0, 0, 255)));

	vertices.append(sf::Vertex(
			sf::Vector2f(endNode.getPixelX(), endNode.getPixelY()), 
			sf::Color(0, 0, 255)));
}

void Edge::set(cdc::Node& endNode, uint cost)
{
	this->endNode = &endNode;
	this->cost = cost;

	if (vertices.getVertexCount() > 0) vertices.clear();

	vertices.append(sf::Vertex(
			sf::Vector2f(startNode->getPixelX(), startNode->getPixelY()), 
			sf::Color(0, 0, 255)));

	vertices.append(sf::Vertex(
			sf::Vector2f(endNode.getPixelX(), endNode.getPixelY()), 
			sf::Color(0, 0, 255)));
}

Node* Edge::getStartNode() const
{
	return startNode;
}

Node* Edge::getEndNode() const
{
	return endNode;
}

uint Edge::getCost() const
{
	return cost;
}

bool Edge::isEmpty() const
{
	return (endNode == nullptr);
}

void Edge::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (endNode != nullptr)
	{
		target.draw(vertices, states);
	}
}