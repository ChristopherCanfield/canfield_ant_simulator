#include "Edge.hpp"
#include "Node.hpp"
#include "PathNode.hpp"
#include "../util/Vector2fAdapter.hpp"

#include <cassert>

// Christopher D. Canfield
// October 2013
// Edge.cpp

using cdc::Edge;
using cdc::Node;
using cdc::PathNode;


Edge::Edge(cdc::Node& startNode) :
	startNode(&startNode),
	endNode(nullptr), 
	cost(999999)
{
	vertices.setPrimitiveType(sf::Lines);
}

Edge::Edge(cdc::Node& startNode, cdc::Node& endNode, float cost) :
	startNode(&startNode),
	endNode(&endNode), 
	cost(cost)
{
	setVertices(startNode, endNode);
}

Edge::Edge(Node& startNode, Node& endNode, int cost) :
	startNode(&startNode),
	endNode(&endNode),
	cost(static_cast<float>(cost))
{
	setVertices(startNode, endNode);
}

void Edge::set(cdc::Node& endNode, float cost)
{
	this->endNode = &endNode;
	this->cost = cost;

	if (vertices.getVertexCount() > 0) vertices.clear();

	setVertices(*startNode, endNode);
}

void Edge::setVertices(Node& startNode, Node& endNode)
{
	vertices.setPrimitiveType(sf::Lines);

	vertices.append(sf::Vertex(
			Vector2fAdapter(startNode.getPixelX(), startNode.getPixelY()), 
			sf::Color(0, 0, 255)));

	vertices.append(sf::Vertex(
			Vector2fAdapter(endNode.getPixelX(), endNode.getPixelY()), 
			sf::Color(0, 0, 255)));

	sf::Vector2f startPoint(startNode.getPixelX(), startNode.getPixelY());
	sf::Vector2f endPoint(endNode.getPixelX(), endNode.getPixelY());
	if (startPoint.x == endPoint.x)
	{
		pheromoneVertices.setPosition(sf::Vector2f(startPoint.x - 25.f, startPoint.y));
		pheromoneVertices.setSize(sf::Vector2f(50.f, abs(startPoint.y - endPoint.y)));
	}
	else
	{
		pheromoneVertices.setPosition(sf::Vector2f(startPoint.x, startPoint.y - 25.f));
		pheromoneVertices.setSize(sf::Vector2f(abs(startPoint.y - endPoint.y), 50.f));
	}
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

float Edge::getCost() const
{
	return cost;
}

uint Edge::getPheromone() const
{
	return pheromone.getStrength();
}

void Edge::increasePheromone()
{
	pheromone.increase();
}

void Edge::decreasePheromone()
{
	pheromone.decrease();
}

void Edge::setPheromoneNextNode(Node& node)
{
	pheromone.setNextNode(node);
}

Node* Edge::getPheromoneNextNode() const
{
	return pheromone.getNextNode();
}

void Edge::update(uint ticks)
{
	const int pheromoneReducationRate = 10;

	if (ticks >= nextPheromoneReduction)
	{
		pheromone.decrease();
		nextPheromoneReduction += pheromoneReducationRate;
	}
}

void Edge::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (endNode != nullptr)
	{
		target.draw(vertices, states);
	}
}

void Edge::drawPheromone(sf::RenderTarget& target, sf::RenderStates states)
{
	auto pheromoneStrength = getPheromone();
	
	if (pheromoneStrength == 0)
	{
		pheromoneVertices.setFillColor(sf::Color::Transparent);
	}
	else if (pheromoneStrength > 8)
	{
		 pheromoneVertices.setFillColor(sf::Color(170, 0,  255, 140));
	}
	else if (pheromoneStrength > 5)
	{
		pheromoneVertices.setFillColor(sf::Color(199, 89, 255, 140));
	}
	else if (pheromoneStrength > 3)
	{
		pheromoneVertices.setFillColor(sf::Color(216, 140, 255, 140));
	}
	else if (pheromoneStrength > 0)
	{
		pheromoneVertices.setFillColor(sf::Color(232, 186, 255, 140));
	}

	if (startNode != nullptr && endNode != nullptr)
	{
		
		target.draw(pheromoneVertices, states);
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