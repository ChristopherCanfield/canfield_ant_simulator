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
	cost(999999),
	nextPheromoneReduction(0)
{
	vertices.setPrimitiveType(sf::Lines);
}

Edge::Edge(cdc::Node& startNode, cdc::Node& endNode, float cost) :
	startNode(&startNode),
	endNode(&endNode), 
	cost(cost),
	nextPheromoneReduction(0)
{
	setVertices(startNode, endNode);
}

Edge::Edge(Node& startNode, Node& endNode, int cost) :
	startNode(&startNode),
	endNode(&endNode),
	cost(static_cast<float>(cost)),
	nextPheromoneReduction(0)
{
	setVertices(startNode, endNode);
}

void Edge::setVertices(Node& startNode, Node& endNode)
{
	vertices.setPrimitiveType(sf::Lines);

	vertices.append(sf::Vertex(
			Vector2fAdapter(startNode.getPixelX<uint>(), startNode.getPixelY<uint>()), 
			sf::Color(0, 0, 255)));

	vertices.append(sf::Vertex(
			Vector2fAdapter(endNode.getPixelX<uint>(), endNode.getPixelY<uint>()), 
			sf::Color(0, 0, 255)));

	pheromoneStrongVertices.setPrimitiveType(sf::Lines);
	sf::Vector2f startPoint(startNode.getPixelX<float>(), startNode.getPixelY<float>());
	sf::Vector2f endPoint(endNode.getPixelX<float>(), endNode.getPixelY<float>());
	pheromoneStrongVertices.append(sf::Vertex(startPoint, sf::Color(220, 0, 0)));
	pheromoneStrongVertices.append(sf::Vertex(endPoint, sf::Color(220, 0, 0)));

	pheromoneMediumVertices.setPrimitiveType(sf::Lines);
	sf::Vector2f startPoint2(startNode.getPixelX<float>(), startNode.getPixelY<float>());
	sf::Vector2f endPoint2(endNode.getPixelX<float>(), endNode.getPixelY<float>());
	pheromoneMediumVertices.append(sf::Vertex(startPoint2, sf::Color(255, 0, 0)));
	pheromoneMediumVertices.append(sf::Vertex(endPoint2, sf::Color(255, 0, 0)));

	pheromoneMediumVertices.setPrimitiveType(sf::Lines);
	sf::Vector2f startPoint3(startNode.getPixelX<float>(), startNode.getPixelY<float>());
	sf::Vector2f endPoint3(endNode.getPixelX<float>(), endNode.getPixelY<float>());
	pheromoneMediumVertices.append(sf::Vertex(startPoint3, sf::Color(255, 120, 0)));
	pheromoneMediumVertices.append(sf::Vertex(endPoint3, sf::Color(255, 120, 0)));
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

void Edge::increasePheromoneToMax()
{
	pheromone.increaseToMax();
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
	const int pheromoneReducationRate = 200;

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

void Edge::draw(sf::RenderTarget &target, sf::RenderStates states, sf::Color color) const
{
	using namespace sf;

	if (endNode != nullptr)
	{
		VertexArray path;
		path.setPrimitiveType(sf::Lines);

		path.append(Vertex(Vector2f(startNode->getPixelX<float>(), startNode->getPixelY<float>()), color));
		path.append(Vertex(Vector2f(endNode->getPixelX<float>(), endNode->getPixelY<float>()), color));

		target.draw(path, states);
	}
}

void Edge::drawPheromone(sf::RenderTarget& target, sf::RenderStates states)
{
	auto pheromoneStrength = getPheromone();
	
	if (pheromoneStrength == 0)
	{
		//pheromoneVertices.(sf::Color::Transparent);
	}
	else if (pheromoneStrength > 6)
	{
		target.draw(pheromoneStrongVertices, states);
	}
	else if (pheromoneStrength > 3)
	{
		target.draw(pheromoneMediumVertices, states);
	}
	else if (pheromoneStrength > 0)
	{
		target.draw(pheromoneWeakVertices, states);
	}

	/*else if (pheromoneStrength > 8)
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
	}*/

	/*if (startNode != nullptr && endNode != nullptr)
	{
		
		target.draw(pheromoneVertices, states);
	}*/
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