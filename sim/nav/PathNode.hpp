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
		PathNode(const PathNode& pathNode);
		PathNode(const Node& node, float cost);
		PathNode(const Node& node, int cost);

		PathNode& operator=(const PathNode& rhs);
	
		const std::vector<std::shared_ptr<Edge>> getEdgeList() const;

		Node& getNode() const;

		float getCost() const;

		bool operator==(const PathNode& other) const;
		bool operator==(const Node& other) const;

	private:
		// Reference to a node. This is a non-owning class.
		Node* node;
		// The cost of the path.
		float cost;
	};
}