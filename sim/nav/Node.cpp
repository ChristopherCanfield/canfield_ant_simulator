#include "Node.hpp"

// Christopher D. Canfield
// October 2013
// Node.cpp

using cdc::Node;
using cdc::Edge;
using cdc::GridLocation;


Node::Node(GridLocation location, int pixelX, int pixelY) :
	location(location), pixelX(pixelX), pixelY(pixelY)
{
}

Node& Node::addEdge(Edge edge, bool addToConnectedNode)
{
	edges.push_back(edge);
	if (addToConnectedNode && edge.getNode() != nullptr)
	{
		edge.getNode()->addEdge(Edge(*this, edge.getCost()), false);
	}
	return *this;
}

std::vector<Edge>& Node::getEdgeList()
{
	return edges;
}

Edge& Node::getEdge(int index)
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