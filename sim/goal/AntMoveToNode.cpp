#include "AntMoveToNode.hpp"
#include "../knowledge/AntPercept.hpp"
#include "../nav/Node.hpp"
#include "../agent/Ant.hpp"
#include "../util/MathHelper.hpp"

#include <iostream>

// Christopher D. Canfield
// November 2013
// AntMoveToNode.cpp

using cdc::AntMoveToNode;
using cdc::Node;
using cdc::AntPercept;
using cdc::Ant;
using namespace cdc::MathHelper;
using namespace std;


AntMoveToNode::AntMoveToNode(Ant& ant, const Node& target, bool debug) :
	target(&target),
	debug(debug),
	AntGoal("AntMoveToNode")
{
	calculateMovementVectors(ant);
	if (debug) cout << "target: (" << target.getRow() << "," << target.getColumn() << "); " <<
			target.getPixelX<int>() << "," << target.getPixelY<int>() << "px" << endl;
}


AntMoveToNode::~AntMoveToNode()
{
}

void AntMoveToNode::update(Ant& ant, uint ticks, AntPercept& percept)
{
	if (ant.getBoundingBox().intersects(target->getBoundingBox()))
	{
		setFinished(true);

		auto antFoodPile = target->getAntFoodPile();
		if (antFoodPile != nullptr)
		{
			auto& foodPositions = ant.kb.lastKnownFoodPosition;
			// Don't add the food position if it was the most recent one added.
			if (foodPositions.empty() || foodPositions.back() != target)
			{
				foodPositions.push_front(target);
			}
		}

		if (ant.stats.isHoldingFood)
		{
			auto& edges = target->getEdgeList();
			for (auto& edge : edges)
			{
				Node* node = nullptr;
				if ((node = edge->getOppositeNode(*ant.kb.lastNodePassed)) != nullptr)
				{
					edge->increasePheromoneToMax();
					edge->setPheromoneNextNode(*ant.kb.lastNodePassed, ticks);
					break;
				}
			}
		}

		ant.kb.lastNodePassed = const_cast<Node*>(target);

		if (debug) cout << "Reached node" << endl;
	}
	else
	{
		// Move the ant toward the target.
		float newPositionX = ant.getPosition().x + (ant.stats.movementVector.x * ant.stats.movementSpeed);
		float newPositionY = ant.getPosition().y + (ant.stats.movementVector.y * ant.stats.movementSpeed);
		ant.setPosition(newPositionX, newPositionY);
	}
}

void AntMoveToNode::reset(Ant& ant, Node& newTarget)
{
	target = &newTarget;
	calculateMovementVectors(ant);
	setFinished(false);
}

void AntMoveToNode::calculateMovementVectors(Ant& ant)
{
	// Turn the ant to face the new target node.
	float angle = MathHelper::angleInRadians(ant.getPosition().x, ant.getPosition().y, 
			target->getPixelX<float>(), target->getPixelY<float>());

	if (MathHelper::radiansToDegrees(debug)) cout << "Angle: " << angle << endl;
	ant.setRotation(MathHelper::radiansToDegrees(angle));
	ant.stats.movementVector.x = cos(angle);
	ant.stats.movementVector.y = sin(angle);
}


void AntMoveToNode::drawPath(sf::RenderTarget& target, sf::RenderStates states, const Node& lastNodePassed) const
{
	if (lastNodePassed != *this->target)
	{
		for (auto& edge : this->target->getEdgeList())
		{
			auto oppNode = edge->getOppositeNode(lastNodePassed);
			if (oppNode != nullptr && oppNode == this->target)
			{
				edge->draw(target, states, sf::Color(0, 255, 178));
				break;
			}
		}
	}
}