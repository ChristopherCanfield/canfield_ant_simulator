#include "AntExplore.hpp"
#include "AntMoveToLocation.hpp"
#include "../agent/Ant.hpp"
#include "../util/Random.hpp"
#include "../util/MathHelper.hpp"
#include "../util/make_unique.hpp"
#include "../sim/nav/NavGraphHelper.hpp"
#include "../sim/nav/GridLocation.hpp"
#include "../sim/nav/Search.hpp"
#include "../worldobject/AntHome.hpp"

#include <cmath>

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



AntExplore::AntExplore()
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
			const auto& target = getNewTarget(ant);
			const auto currentNode = (ant.getNode() != nullptr) ? ant.getNode() : &ant.kb.home.getNode();
			
			// Set the path to the target.
			path = Search::aStar(*currentNode, target, Search::straightLineHeuristic);

			// Pop the first node off the queue, because that's the node that the
			// ant is currently on.
			path.pop_front();
		}
		else 
		{
			processNextInPath(ant);
		}
	}
	else
	{
		subgoal->update(ant, ticks, percept);
	}
}

Node& AntExplore::getNewTarget(const Ant& ant)
{
	auto& navGraphHelper = ant.kb.navGraphHelper;
	const int maxRow = static_cast<int>(navGraphHelper.getMaxRow());
	const int maxColumn = static_cast<int>(navGraphHelper.getMaxColumn());

	uint row = 0;
	uint column = 0;
	Random rand;
	bool validNodeLocation = false;

	while (!validNodeLocation)
	{
		row = rand.getInteger(0, maxRow);
		column = rand.getInteger(0, maxColumn);

		validNodeLocation = navGraphHelper.isValid(GridLocation(row, column));
	}

	return *navGraphHelper.getNode(GridLocation(row, column));
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
		subgoal = make_unique<AntMoveToLocation>(ant, *target);

		float angle = MathHelper::angleInRadians(ant.getPosition().x, ant.getPosition().y, 
				target->getPixelX(), target->getPixelY());

		ant.stats.movementVector.x = cos(angle);
		ant.stats.movementVector.y = sin(angle);
	}
}