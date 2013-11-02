#pragma once

#include "Node.hpp"
#include "Edge.hpp"

#include <vector>


class PathNode
{
public:
	PathNode();
	
/	const std::vector<Edge*> getEdges() const;

	const Node& getNode() const;

	uint getCost() const;

private:
	const std::vector<Edge*>& edges;
	const Node& node;

};

