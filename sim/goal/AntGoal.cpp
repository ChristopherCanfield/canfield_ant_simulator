#include "AntGoal.hpp"
#include "../nav/Node.hpp"

// Christopher D. Canfield
// November 2013
// AntGoal.cpp

using cdc::AntGoal;
using cdc::Ant;
using cdc::AntPercept;
using cdc::Node;

using std::string;



AntGoal::AntGoal(string goalName) :
	finished(false),
	goalName(goalName)
{
}


AntGoal::~AntGoal()
{
}


bool AntGoal::isFinished() const
{
	return finished;
}

void AntGoal::setFinished(bool finished)
{
	this->finished = finished;
}

void AntGoal::drawPath(sf::RenderTarget& target, sf::RenderStates states, const Node& lastNodePassed) const
{
	// Default implementation: do nothing.
}

string AntGoal::toString() const
{
	return goalName;
}