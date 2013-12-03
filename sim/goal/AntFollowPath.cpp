#include "AntFollowPath.hpp"
#include "../nav/Node.hpp"
#include "../nav/NavGraphHelper.hpp"
#include "../nav/Search.hpp"
#include "../goal/AntGoal.hpp"
#include "../goal/AntMoveToNode.hpp"
#include "../util/make_unique.hpp"

#include <cassert>
#include <iostream>

// Christopher D. Canfield
// November 2013
// AntFollowPath.cpp

using namespace cdc;
using namespace std;


AntFollowPath::AntFollowPath(Ant& ant, const Node& target, bool debug) :
	debug(debug),
	AntGoal("AntFollowPath")
{
	path = Search::aStar(ant.getNode(), target, Search::straightLineHeuristic);
	
	if (debug)
	{
		cout << "Path: ";
		Search::printPath(path);
	}

	subgoal = make_unique<AntMoveToNode>(ant, *path.front(), debug);
}


AntFollowPath::~AntFollowPath()
{
}


void AntFollowPath::update(Ant& agent, uint ticks, AntPercept& percept)
{
	if (!subgoal->isFinished())
	{
		AntPercept antPercept(percept);
		subgoal->update(agent, ticks, antPercept);
	}
	else
	{
		path.pop_front();
		if (path.empty())
		{
			setFinished(true);
		}
		else
		{
			dynamic_cast<AntMoveToNode*>(subgoal.get())->reset(agent, *path.front());
		}
	}
}

void AntFollowPath::drawPath(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (!path.empty())
	{
		// TODO: Draw the path.
	}
}

std::string AntFollowPath::toString() const
{
	if (subgoal != nullptr)
	{
		return AntGoal::toString() + " | Subgoal: " + subgoal->toString();
	}
	else
	{
		return AntGoal::toString();
	}
}