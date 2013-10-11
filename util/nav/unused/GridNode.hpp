#pragma once

// Christopher D. Canfield
// October 2013
// GridNode.hpp

#include "../../Typedefs.hpp"
#include "../Edge.hpp"
#include "../GridLocation.hpp"

#include <memory>


// A node in a grid-based graph.
class GridNode
{
public:
	GridNode(GridLocation gl, uint x, uint y);
	~GridNode();

	void setUp(Edge edge);
	Edge getUp() const;

	void setDown(Edge edge);
	Edge getDown() const;

	void setLeft(Edge edge);
	Edge getLeft() const;

	void setRight(Edge edge);
	Edge getRight() const;

	uint getX() const;

	uint getY() const;

	GridLocation getGridLocation() const;

private:
	Edge upEdge;
	Edge downEdge;
	Edge leftEdge;
	Edge rightEdge;

	uint pixelX;
	uint pixelY;

	GridLocation location;
};
