#include "AntGoHome.hpp"
#include "../nav/Node.hpp"
#include "../nav/Search.hpp"
#include "../worldobject/AntHome.hpp"

// Christopher D. Canfield
// November 2013
// AntGoHome.cpp

using cdc::AntGoHome;
using cdc::Ant;
using cdc::AntPercept;
using cdc::Node;
using cdc::Search;


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

	if (path.empty())
	{

		path = Search::aStar(*ant.kb.lastNodePassed, ant.kb.home.getNode(), 
				Search::straightLineHeuristic);
		// Pop off the start node, because we already passed it.
		path.pop_front();

		// Set the first node in the path.
		currentTarget = path.front();
		path.pop_front();
	}
	else
	{

	}
}
