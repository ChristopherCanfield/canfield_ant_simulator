#include "Node.hpp"
#include "../util/Vector2fAdapter.hpp"

#include <stdexcept>

// Christopher D. Canfield
// October 2013
// Node.cpp

using cdc::Node;
using cdc::Edge;
using cdc::GridLocation;
using std::shared_ptr;
using std::out_of_range;


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
	/*for (uint i = 0u; i < edges.size(); ++i)
	{
		if (edges[i] != nullptr)
		{
			auto node = edges[i]->getOppositeNode(*this);
			node->removeEdge(*edges[i]);
			
			delete edges[i];
			edges[i] = nullptr;
		}
	}*/
}

Node& Node::addEdge(shared_ptr<Edge> edge, bool addEdgeToOppositeNode)
{
	for (auto& e : edges)
	{
		if (edge == e)
		{
			return *this;
		}
	}
	edges.push_back(edge);
	
	if (addEdgeToOppositeNode)
	{
		if (edge->getNode1() != nullptr)
		{
			edge->getNode1()->addEdge(edge, false);
		}
	}

	return *this;
}

void Node::removeEdge(Edge& edge, bool removeEdgeFromOpposite)
{
	for (auto e = edges.begin(); e != edges.end(); ++e)
	{
		if (*(*e) == edge)
		{
			if (removeEdgeFromOpposite)
			{
				(*e)->getOppositeNode(*this)->removeEdge(*(*e), false);
			}
			edges.erase(e);
			return;
		}
	}
}

const std::vector<shared_ptr<Edge>>& Node::getEdgeList() const
{
	return edges;
}

const Edge& Node::getEdge(uint index) const
{
	if (index < edges.size())
	{
		return *edges[index].get();
	}
	else
	{
		throw out_of_range("Index provided to Node::getEdge is out of range. Index: " + index);
	}
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