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


AntMoveToNode::AntMoveToNode(Ant& ant, Node& target, bool debug) :
	target(&target),
	debug(debug),
	AntGoal("AntMoveToNode")
{
	calculateMovementVectors(ant);
	if (debug) cout << "target: (" << target.getRow() << "," << target.getColumn() << "); " <<
			target.getPixelX() << "," << target.getPixelY() << "px" << endl;
}


AntMoveToNode::~AntMoveToNode()
{
}

void AntMoveToNode::update(Ant& ant, uint ticks, AntPercept& percept)
{
	if (ant.getBoundingBox().intersects(target->getBoundingBox()))
	{
		setFinished(true);
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
			target->getPixelX(), target->getPixelY());

	if (MathHelper::radiansToDegrees(debug)) cout << "Angle: " << angle << endl;
	ant.setRotation(MathHelper::radiansToDegrees(angle));
	ant.stats.movementVector.x = cos(angle);
	ant.stats.movementVector.y = sin(angle);
}