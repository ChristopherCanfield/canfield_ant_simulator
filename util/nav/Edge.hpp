#pragma once

// Christopher D. Canfield
// October 2013
// Edge.hpp

class GridNode;

#include "../Typedefs.hpp"

// An edge between nodes in the graph.
class Edge
{
public:
	Edge();
	Edge(GridNode& node, uint cost);

	void set(GridNode& node, uint cost);

	GridNode& getNode() const;

	uint getCost() const;

private:
	GridNode* node;
	uint cost;
};

