#pragma once

#include "Node.hpp"
#include "../util/Typedefs.hpp"

#include <functional>


namespace cdc
{

	class PathKey
	{
	public:
		PathKey(const Node& startNode, const Node& endNode);
		const Node& getStartNode() const;
		const Node& getEndNode() const;
		bool operator==(const PathKey& other) const;

	private:
		PathKey& operator=(const PathKey& rhs);
		const Node& startNode;
		const Node& endNode;
	};
}


namespace std
{
	template<>
	class hash<cdc::PathKey>
	{
	public:
		// Adapted from Joshua Bock, "Effective Java, 2nd Edition".
		std::size_t operator()(const cdc::PathKey& key) const
		{
			std::size_t result = 17;
			result = 31 * result + key.getStartNode().getColumn();
			result = 31 * result + key.getStartNode().getRow();
			result = 31 * result + key.getEndNode().getColumn();
			result = 31 * result + key.getEndNode().getRow();

			return result;
		}
	};
}