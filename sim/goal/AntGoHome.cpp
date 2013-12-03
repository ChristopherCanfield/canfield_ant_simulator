#include "AntGoHome.hpp"
#include "AntFollowPath.hpp"
#include "../nav/Node.hpp"
#include "../nav/Search.hpp"
#include "../worldobject/AntHome.hpp"
#include "../agent/Ant.hpp"
#include "../util/make_unique.hpp"


// Christopher D. Canfield
// November 2013
// AntGoHome.cpp

using cdc::AntGoHome;
using cdc::Ant;
using cdc::AntPercept;
using cdc::Node;
using cdc::Search;
using cdc::AntMoveToNode;
using cdc::AntHome;


AntGoHome::AntGoHome() :
	currentTarget(nullptr),
	AntGoal("AntGoHome")
{
}


AntGoHome::~AntGoHome()
{
}

void AntGoHome::update(Ant& ant, uint ticks, AntPercept& percept)
{
	if (isFinished())
	{
		return;
	}

	if (subgoal == nullptr)
	{
		subgoal = make_unique<AntFollowPath>(ant, ant.kb.home.getNode());
	}
	else if (subgoal->isFinished())
	{
		setFinished(true);
	}
	else
	{
		subgoal->update(ant, ticks, percept);
	}
}

void AntGoHome::drawPath(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (!path.empty())
	{
		// TODO: Draw the path.
	}
}

std::string AntGoHome::toString() const
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