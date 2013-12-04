#include "AntFindFood.hpp"
#include "AntMoveToNode.hpp"
#include "AntGoalHelper.hpp"
#include "../agent/Ant.hpp"
#include "../nav/Node.hpp"
#include "../nav/Search.hpp"
#include "../util/make_unique.hpp"


// Christopher D. Canfield
// November 2013
// AntFindFood.cpp

using cdc::AntFindFood;
using cdc::AntGoalHelper;
using cdc::AntMoveToNode;
using cdc::Ant;
using cdc::AntPercept;
using cdc::Node;
using cdc::Search;


AntFindFood::AntFindFood() :
	AntGoal("AntFindFood"),
	foodFound(false),
	nextNode(nullptr)
{
}


AntFindFood::~AntFindFood()
{
}


void AntFindFood::update(Ant& ant, uint ticks, AntPercept& percept)
{
	// 1. Check last known food location.
	// 2. If pheromone is found at any time, follow that trail.
	// 3. Otherwise, search randomly until food is found.
	//assert(false);

	if (isFinished())
	{
		return;
	}

	if (foodFound)
	{
		setFinished(true);
		return;
	}

	if (subgoal == nullptr || subgoal->isFinished())
	{
		if (ant.kb.lastNodePassed->getAntFoodPile() != nullptr)
		{
			foodFound = true;
		}
		else
		{
			setSubgoal(ant);
		}
	}
	else
	{
		subgoal->update(ant, ticks, percept);
	}
}

void AntFindFood::setSubgoal(Ant& ant)
{
	// If path is not empty, check the recently reached node for pheromones.
	// If pheromones are found, go to that node. If they aren't found,
	// continue following the path.
	if (!path.empty())
	{
		auto target = path.front();
		path.pop_front();
		auto pheromoneTarget = checkEdgesForPheromone(*ant.kb.lastNodePassed);
		if (pheromoneTarget != nullptr)
		{
			target = pheromoneTarget;
			path.clear();
		}
		nextNode = target;

		if (subgoal == nullptr)
		{
			subgoal = make_unique<AntMoveToNode>(ant, *target);
		}
		else
		{
			dynamic_cast<AntMoveToNode*>(subgoal.get())->reset(ant, *target);
		}
	}
	// If not following a path, attempt to go to the last known food position.
	else if (!ant.kb.lastKnownFoodPosition.empty())
	{
		auto target = ant.popLastKnownFoodPosition();
		path = Search::aStar(*ant.kb.lastNodePassed, *target, Search::manhattanHeuristic);
		if (path.empty())
		{
			return;
		}

		auto next = path.front();
		path.pop_front();
		auto pheromoneTarget = checkEdgesForPheromone(*ant.kb.lastNodePassed);
		if (pheromoneTarget != nullptr)
		{
			next = pheromoneTarget;
			path.clear();
		}
		nextNode = next;

		if (subgoal == nullptr)
		{
			subgoal = make_unique<AntMoveToNode>(ant, *next);
		}
		else
		{
			dynamic_cast<AntMoveToNode*>(subgoal.get())->reset(ant, *next);
		}
	}
	// If not following a path and there is no last known food position, set a random target.
	else
	{
		auto& target = AntGoalHelper::getNewTarget(ant.kb.navGraphHelper, *ant.kb.lastNodePassed);
		path = Search::aStar(*ant.kb.lastNodePassed, target, Search::manhattanHeuristic);
		auto next = path.front();
		path.pop_front();
		auto pheromoneTarget = checkEdgesForPheromone(*ant.kb.lastNodePassed);
		if (pheromoneTarget != nullptr)
		{
			next = pheromoneTarget;
			path.clear();
		}
		nextNode = next;

		if (subgoal == nullptr)
		{
			subgoal = make_unique<AntMoveToNode>(ant, *next);
		}
		else
		{
			dynamic_cast<AntMoveToNode*>(subgoal.get())->reset(ant, *next);
		}
	}
}

// Checks the current node's edges for pheromones. If found, the node that
// the pheromone points to is returned. Otherwise, nullptr is returned.
Node* AntFindFood::checkEdgesForPheromone(Node& currentNode)
{
	Node* mostRecentNode = nullptr;
	uint mostRecentTime = 0;
	for (auto& edge : currentNode.getEdgeList())
	{
		if (edge->getPheromone() > 0 && *edge->getPheromoneNextNode() != currentNode && 
			edge->getPheromoneNextNodeTickTime() > mostRecentTime)
		{
			mostRecentNode = edge->getPheromoneNextNode();
			mostRecentTime = edge->getPheromoneNextNodeTickTime();
		}
	}
	return mostRecentNode;
}

std::string AntFindFood::toString() const
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

void AntFindFood::drawPath(sf::RenderTarget& target, sf::RenderStates states, const Node& lastNodePassed) const
{
	if (!path.empty())
	{
		AntGoalHelper::drawPath(target, states, path, (nextNode != nullptr) ? *nextNode : lastNodePassed);
	}
	if (subgoal != nullptr)
	{
		subgoal->drawPath(target, states, lastNodePassed);
	}
}