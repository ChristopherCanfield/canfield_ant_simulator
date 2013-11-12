#include "AntGoHome.hpp"
#include "AntMoveToLocation.hpp"
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
using cdc::AntMoveToLocation;
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
		auto homeLocation = ant.kb.home.getNode();
		path.pop_front();

		if (path.empty())
		{
			setFinished(true);
		}


		// TODO: finish this.
	}
	else
	{
		subgoal->update(ant, ticks, percept);
	}
}
