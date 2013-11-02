#pragma once

#include "Node.hpp"
#include "Edge.hpp"

#include <vector>

// Christopher D. Canfield
// October 2013
// PathNode.hpp


namespace cdc
{
	// A wrapper around a Node that includes the cost of getting to the Node
	// (edge cost + heuristic cost).
	class PathNode
	{
	public:
		PathNode(Node& node, uint cost);
	
		const std::vector<Edge*> getEdgeList() const;

		Node& getNode() const;

		uint getCost() const;

		bool operator==(const PathNode& other) const;
		bool operator==(const Node& other) const;

	private:
		Node& node;
		uint cost;
	};
}