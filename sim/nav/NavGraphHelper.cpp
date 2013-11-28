#include "NavGraphHelper.hpp"

#include <algorithm>

// Christopher D. Canfield
// November 2013
// NavGraphHelper.cpp

using cdc::GridLocation;
using cdc::Node;
using cdc::NavGraphHelper;
using std::unique_ptr;
using std::vector;


class MatchesLocation
{
public:
	MatchesLocation(GridLocation& targetLocation) :
		target(targetLocation)
	{
	}

	std::size_t operator()(const Node& node) const
	{
		return (target.getRow() == node.getRow() &&
				target.getColumn() == node.getColumn());
	}

private:
	MatchesLocation& operator=(const MatchesLocation& other);

	GridLocation& target;
}; 


NavGraphHelper::NavGraphHelper(const std::vector<Node>& graph) :
	navGraph(&graph),
	maxRow(0),
	maxColumn(0)
{
	for (auto& node : *navGraph)
	{
		if (node.getRow() > maxRow)
		{
			maxRow = node.getRow();
		}

		if (node.getColumn() > maxColumn)
		{
			maxColumn = node.getColumn();
		}
	}
}

NavGraphHelper::NavGraphHelper() :
	maxRow(0),
	maxColumn(0),
	navGraph(nullptr)
{
}

NavGraphHelper::~NavGraphHelper()
{
}
		
bool NavGraphHelper::isValid(GridLocation nodeLocation) const
{
	MatchesLocation predicateFunctor(nodeLocation);
	auto foundItem = std::find_if(navGraph->cbegin(), navGraph->cend(), predicateFunctor);
	if (foundItem != navGraph->cend())
	{
		return (!foundItem->getEdgeList().empty());
	}
	else
	{
		return false;
	}
}

uint NavGraphHelper::getMaxRow() const
{
	return maxRow;
}

uint NavGraphHelper::getMaxColumn() const
{
	return maxColumn;
}

// This may be overly complicated. Storing points to the rows and columns in a 
// multi-dimensional vector may be more computationally efficient, at the cost
// of additional memory usage (11/28/2013).
Node* NavGraphHelper::getNode(GridLocation location)
{
	if (nodes.count(location) != 0)
	{
		return nodes[location];
	}
	else
	{
		MatchesLocation predicateFunctor(location);
		auto foundNode = std::find_if(navGraph->cbegin(), navGraph->cend(), predicateFunctor);
		if (foundNode == navGraph->cend())
		{
			return nullptr;
		}

		Node* node = const_cast<Node*>(&(*foundNode));
		nodes[location] = node;
		return node;
	}
}