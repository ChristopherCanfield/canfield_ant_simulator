#include "GridNode.hpp"


GridNode::GridNode(GridLocation gl, uint x, uint y) :
	location(gl), pixelX(x), pixelY(y)
{
}

GridNode::~GridNode() {}

void GridNode::setUp(Edge edge)
{
	this->upEdge = edge;
}

Edge GridNode::getUp() const
{
	return upEdge;
}

void GridNode::setDown(Edge edge)
{
	this->downEdge = edge;
}

Edge GridNode::getDown() const
{
	return downEdge;
}

void GridNode::setLeft(Edge edge)
{
	this->leftEdge = edge;
}

Edge GridNode::getLeft() const
{
	return leftEdge;
}

void GridNode::setRight(Edge edge)
{
	this->rightEdge = edge;
}

Edge GridNode::getRight() const
{
	return rightEdge;
}

uint GridNode::getX() const
{
	return pixelX;
}

uint GridNode::getY() const
{
	return pixelY;
}

GridLocation GridNode::getGridLocation() const
{
	return location;
}