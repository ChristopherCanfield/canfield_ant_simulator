#include "NavGraph.hpp"

#include <algorithm>

// Christopher D. Canfield
// November 2013
// NavGraph.cpp

using cdc::GridLocation;
using cdc::Node;
using cdc::NavGraph;
using std::unique_ptr;


class MatchesLocation
{
public:
	MatchesLocation(GridLocation& targetLocation) :
		target(targetLocation)
	{
	}

	std::size_t operator()(const unique_ptr<Node>& node) const
	{
		return (target.getRow() == node->getRow() &&
				target.getColumn() == node->getColumn());
	}

private:
	MatchesLocation& operator=(const MatchesLocation& other);

	GridLocation& target;
}; 


NavGraph::NavGraph(std::vector<std::unique_ptr<Node>>&& graph) :
	navGraph(std::move(graph))
{
}

NavGraph::~NavGraph()
{
}
		
bool NavGraph::isValid(GridLocation nodeLocation)
{
	MatchesLocation predicateFunctor(nodeLocation);
	auto foundItem = std::find_if(navGraph.begin(), navGraph.end(), predicateFunctor);
	return (foundItem != navGraph.end());
}