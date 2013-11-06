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
		// Adapted from Bjarne Stroustrup, "A Tour of C++"
		std::size_t operator()(const cdc::PathKey& key) const
		{
			return hash<uint>()(key.getStartNode().getColumn()) ^
					hash<uint>()(key.getStartNode().getRow()) ^
					hash<uint>()(key.getEndNode().getColumn()) ^
					hash<uint>()(key.getEndNode().getRow());
		}
	};
}