#include "AntFindFood.hpp"
#include "../agent/Ant.hpp"
#include "../nav/Node.hpp"


// Christopher D. Canfield
// November 2013
// AntFindFood.cpp

using cdc::AntFindFood;
using cdc::Ant;
using cdc::AntPercept;
using cdc::Node;


AntFindFood::AntFindFood() :
	AntGoal("AntFindFood"),
	foodFound(false)
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

	if (foodFound)
	{
		setFinished(true);
		return;
	}

	if (subgoal == nullptr || !subgoal->isFinished())
	{
		if (ant.kb.lastNodePassed->getAntFoodPile() != nullptr)
		{
			foodFound = true;
		}
		else
		{
			// TODO: complete this.
		}
	}
	else
	{
		// TODO: complete this.
	}
}

void AntFindFood::setSubgoal(Ant& ant)
{
	auto lastKnowFood = ant.popLastKnownFoodPosition();
	// TODO: implement the rest of this.
}

// Checks the current node's edges for pheromones. If found, the node that
// the pheromone points to is returned. Otherwise, nullptr is returned.
Node* AntFindFood::checkEdgesForPheromone(Node& currentNode)
{
	for (auto& edge : currentNode.getEdgeList())
	{
		if (edge->getPheromone() > 0 && *edge->getPheromoneNextNode() != currentNode)
		{
			return edge->getPheromoneNextNode();
		}
	}
	return nullptr;
}

void AntFindFood::drawPath(sf::RenderTarget& target, sf::RenderStates states) const
{
	// TODO: draw the path.
}
