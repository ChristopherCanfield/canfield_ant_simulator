#include "AntFollowPath.hpp"
#include "../nav/Node.hpp"
#include "../nav/NavGraphHelper.hpp"
#include "../nav/Search.hpp"
#include "AntGoal.hpp"
#include "AntMoveToNode.hpp"
#include "AntGoalHelper.hpp"
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
	if (path.empty())
	{
		// This should only occur if the ant is already on the target node.
		setFinished(true);
		if (debug) cout << "Unable to calculate path from " << ant.getNode().toString() << " to " << target.toString() << endl;
		return;
	}


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

void AntFollowPath::drawPath(sf::RenderTarget& target, sf::RenderStates states, const Node& lastNodePassed) const
{
	if (!path.empty())
	{
		AntGoalHelper::drawPath(target, states, path, lastNodePassed);
	}
	if (subgoal != nullptr)
	{
		subgoal->drawPath(target, states, lastNodePassed);
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