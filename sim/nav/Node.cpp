#include "Node.hpp"

// Christopher D. Canfield
// October 2013
// Node.cpp

using cdc::Node;
using cdc::Edge;
using cdc::GridLocation;


Node::Node(GridLocation location, int pixelX, int pixelY) :
	location(location), 
	pixelX(pixelX), 
	pixelY(pixelY), 
	circle(5)
{
	circle.setOrigin(circle.getLocalBounds().width / 2.f, circle.getLocalBounds().height / 2.f);
	circle.setPosition(static_cast<float>(pixelX), static_cast<float>(pixelY));
	circle.setFillColor(sf::Color::Blue);
}

Node& Node::addEdge(std::shared_ptr<Edge> edge)
{
	edges.push_back(edge);
	return *this;
}

std::vector<std::shared_ptr<Edge>>& Node::getEdgeList()
{
	return edges;
}

std::shared_ptr<Edge> Node::getEdge(uint index)
{
	return edges[index];
}

int Node::getPixelX() const
{
	return pixelX;
}

int Node::getPixelY() const
{
	return pixelY;
}

uint Node::getRow() const
{
	return location.getRow();
}

uint Node::getColumn() const
{
	return location.getColumn();
}

void Node::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(circle, states);
}