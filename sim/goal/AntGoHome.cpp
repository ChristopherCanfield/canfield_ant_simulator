#include "AntGoHome.hpp"
#include "AntMoveToNode.hpp"
#include "../nav/Node.hpp"
#include "../nav/Search.hpp"
#include "../worldobject/AntHome.hpp"
#include "../agent/Ant.hpp"

// Christopher D. Canfield
// November 2013
// AntGoHome.cpp

using cdc::AntGoHome;
using cdc::Ant;
using cdc::AntPercept;
using cdc::Node;
using cdc::Search;
using cdc::AntMoveToNode;
using cdc::AntHome;


AntGoHome::AntGoHome() :
	currentTarget(nullptr)
{
}


AntGoHome::~AntGoHome()
{
}

void AntGoHome::update(Ant& ant, uint ticks, AntPercept& percept)
{
	if (isFinished())
	{
		return;
	}

	if (subgoal == nullptr || path.empty())
	{
		// If the path is empty, and the goal has not been reached, create a new path
		// to the home.
		path = Search::aStar(*ant.kb.lastNodePassed, ant.kb.home.getNode(), 
				Search::straightLineHeuristic);
		
		// Pop off the start node, because we already passed it.
		path.pop_front();

		// Set the first node in the path.
		currentTarget = path.front();
		path.pop_front();
	}
	else if (subgoal->isFinished())
	{
		auto& homeLocation = ant.kb.home.getNode();
		path.pop_front();

		// If the path is now empty, we've reached the end, so set finished to true.
		if (path.empty())
		{
			setFinished(true);
		}
		// If the path is not empty, set the MoveToLocation subgoal to go to the 
		// next node.
		else
		{
			AntMoveToNode* moveToLocationGoal = dynamic_cast<AntMoveToNode*>(subgoal.get());
			moveToLocationGoal->reset(ant, *path.front());
		}
	}
	else
	{
		subgoal->update(ant, ticks, percept);
	}
}
