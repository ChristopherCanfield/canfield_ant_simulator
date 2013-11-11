#include "AntExplore.hpp"
#include "../util/Random.hpp"

// Christopher D. Canfield
// November 2013
// AntExplore.cpp

using cdc::AntExplore;
using cdc::Ant;
using cdc::AntPercept;
using cdc::Random;


AntExplore::AntExplore()
{
}


AntExplore::~AntExplore()
{
}

void AntExplore::update(Ant& agent, uint ticks, AntPercept& percept)
{
	if (isFinished())
	{
		return;
	}

	if (path.empty())
	{
		uint row = 0;
		uint column = 0;
		bool validNodeLocation = false;

		while (!validNodeLocation)
		{
			
		}
	}

}