#include "Node.hpp"
#include "../util/Vector2fAdapter.hpp"

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
	circle.setPosition(Vector2fAdapter(pixelX, pixelY));
	circle.setFillColor(sf::Color::Blue);
}

Node::~Node()
{
	for (uint i = 0u; i < edges.size(); ++i)
	{
		if (edges[i] != nullptr)
		{
			auto node = edges[i]->getOppositeNode(*this);
			node->removeEdge(*edges[i]);
			
			delete edges[i];
			edges[i] = nullptr;
		}
	}
}

Node& Node::addEdge(Edge& edge, bool addEdgeToOppositeNode)
{
	for (auto& e : edges)
	{
		if (&edge == e)
		{
			return *this;
		}
	}
	edges.push_back(&edge);
	
	if (addEdgeToOppositeNode)
	{
		if (edge.getNode1() != nullptr)
		{
			edge.getNode1()->addEdge(edge, false);
		}
	}

	return *this;
}

void Node::removeEdge(Edge& edge)
{
	for (uint i = 0u; i < edges.size(); ++i)
	{
		if (edges[i] == &edge)
		{
			edges[i] = nullptr;
		}
	}
}

const std::vector<Edge*>& Node::getEdgeList() const
{
	return edges;
}

const Edge* Node::getEdge(uint index) const
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

bool Node::operator==(const Node& other) const
{
	return (getColumn() == other.getColumn() &&
			getRow() == other.getRow());
}

bool Node::operator!=(const Node& other) const
{
	return !(*this == other);
}