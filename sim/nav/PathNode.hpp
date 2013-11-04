#pragma once

#include "Node.hpp"
#include "Edge.hpp"

#include <vector>
#include <memory>

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
		PathNode(const Node& node, uint cost);
		PathNode operator=(const PathNode& rhs);
	
		const std::vector<std::shared_ptr<Edge>> getEdgeList() const;

		Node& getNode() const;

		uint getCost() const;

		bool operator==(const PathNode& other) const;
		bool operator==(const Node& other) const;

	private:
		Node& node;
		uint cost;
	};
}