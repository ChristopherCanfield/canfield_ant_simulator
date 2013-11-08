#include "AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntGoal.cpp

using cdc::AntGoal;
using cdc::Ant;
using cdc::AntPercept;



AntGoal::AntGoal() :
	finished(false)
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