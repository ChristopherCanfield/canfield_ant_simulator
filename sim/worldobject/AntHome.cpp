#include "AntHome.hpp"

// Christopher D. Canfield
// November 2013
// AntHome.hpp

using cdc::AntHome;


AntHome::AntHome() :
	foodCount(0)
{
}


AntHome::~AntHome()
{
}


uint AntHome::getFoodCount() const
{
	return foodCount;
}

bool AntHome::takeFood()
{
	if (foodCount > 0)
	{
		--foodCount;
		return true;
	}
	else
	{
		return false;
	}
}

void AntHome::addFood()
{
	++foodCount;
}