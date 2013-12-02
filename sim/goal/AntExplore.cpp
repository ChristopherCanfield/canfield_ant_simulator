#include "AntExplore.hpp"
#include "AntMoveToNode.hpp"
#include "AntGoalHelper.hpp"
#include "../agent/Ant.hpp"
#include "../util/Random.hpp"
#include "../util/MathHelper.hpp"
#include "../util/make_unique.hpp"
#include "../sim/nav/NavGraphHelper.hpp"
#include "../sim/nav/GridLocation.hpp"
#include "../sim/nav/Search.hpp"
#include "../worldobject/AntHome.hpp"

#include <cmath>
#include <iostream>

// Christopher D. Canfield
// November 2013
// AntExplore.cpp

using cdc::AntExplore;
using cdc::Ant;
using cdc::AntPercept;
using cdc::Random;
using cdc::Node;
using cdc::GridLocation;
using cdc::AntHome;
using cdc::AntGoalHelper;

using std::cout;
using std::endl;



AntExplore::AntExplore(bool debug) :
	debug(debug),
	AntGoal("AntExplore")
{
}

AntExplore::~AntExplore()
{
}

void AntExplore::update(Ant& ant, uint ticks, AntPercept& percept)
{
	using namespace std;

	if (isFinished())
	{
		return;
	}

	if (subgoal == nullptr || subgoal->isFinished())
	{
		if (path.empty())
		{
			// if the path is empty, get a new target.
			const auto& target = AntGoalHelper::getNewTarget(ant.kb.navGraphHelper, *ant.kb.lastNodePassed);
			const auto& currentNode = ant.getNode();
			
			// Set the path to the target.
			path = Search::aStar(currentNode, target, Search::straightLineHeuristic);

			if (debug) cout << "Target: " << target.getRow() << "," << target.getColumn() << endl;
		}
		processNextInPath(ant);
	}
	else
	{
		subgoal->update(ant, ticks, percept);
	}
}



void AntExplore::processNextInPath(Ant& ant)
{
	// if the ant has reached the node in the current path, pop the node and 
	// get the next node. If no nodes remain in the path, set finished to true.
	path.pop_front();

	if (path.empty())
	{
		setFinished(true);
	}
	else
	{
		// Turn the ant to face the new target node.
		auto& target = path.front();
		subgoal = make_unique<AntMoveToNode>(ant, *target);
	}
}

void AntExplore::drawPath(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (!path.empty())
	{
		// TODO: Draw the path.
	}
}