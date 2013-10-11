#pragma once

// Christopher D. Canfield
// October 2013
// Edge.hpp

class Node;

#include "../Typedefs.hpp"

// An edge between nodes in the graph.
class Edge
{
public:
	Edge();
	Edge(Node& node, uint cost);

	void set(Node& node, uint cost);

	Node* getNode() const;

	uint getCost() const;
	
	bool isEmpty() const;

private:
	Node* node;
	uint cost;
};

