#include "AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntGoal.cpp

using cdc::AntGoal;
using cdc::Ant;
using cdc::AntPercept;

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

string AntGoal::toString() const
{
	return goalName;
}