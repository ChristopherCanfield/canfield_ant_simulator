#include "AntMoveToLocation.hpp"
#include "../knowledge/AntPercept.hpp"
#include "../nav/Node.hpp"
#include "../agent/Ant.hpp"
#include "../util/MathHelper.hpp"

// Christopher D. Canfield
// November 2013
// AntMoveToLocation.cpp

using cdc::AntMoveToLocation;
using cdc::Node;
using cdc::AntPercept;
using cdc::Ant;
using namespace cdc::MathHelper;


AntMoveToLocation::AntMoveToLocation(Ant& ant, Node& target) :
	target(&target)
{
	calculateMovementVectors(ant);
}


AntMoveToLocation::~AntMoveToLocation()
{
}

void AntMoveToLocation::update(Ant& ant, uint ticks, AntPercept& percept)
{
	if (ant.getBoundingBox().intersects(target->getBoundingBox()))
	{
		setFinished(true);
	}
	else
	{
		// Move the ant toward the target.
		float newPositionX = ant.getPosition().x + (ant.stats.movementVector.x * ant.stats.movementSpeed);
		float newPositionY = ant.getPosition().y + (ant.stats.movementVector.y * ant.stats.movementSpeed);
		ant.setPosition(newPositionX, newPositionY);
	}
}

void AntMoveToLocation::reset(Ant& ant, Node& newTarget)
{
	target = &newTarget;
	calculateMovementVectors(ant);
	setFinished(false);
}

void AntMoveToLocation::calculateMovementVectors(Ant& ant)
{
	// Turn the ant to face the new target node.
	float angle = MathHelper::angleInRadians(ant.getPosition().x, ant.getPosition().y, 
			target->getPixelX(), target->getPixelY());

	ant.stats.movementVector.x = cos(angle);
	ant.stats.movementVector.y = sin(angle);
}