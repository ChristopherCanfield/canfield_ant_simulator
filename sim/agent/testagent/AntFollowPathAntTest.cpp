#include "AntFollowPathAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../nav/Search.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"
#include "../../goal/AntFollowPath.hpp"
#include "../util/make_unique.hpp"

#include <cassert>
#include <iostream>

// Christopher D. Canfield
// November 2013
// AntFollowPathAntTest.cpp

using namespace cdc;
using namespace std;


AntFollowPathAntTest::AntFollowPathAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode, const Node& targetNode) :
	AntGoalTester(manager, home, navGraphHelper, startNode)
{
	goal = make_unique<AntFollowPath>(*this, targetNode, true);
}

AntFollowPathAntTest::~AntFollowPathAntTest()
{
}

void AntFollowPathAntTest::update(long ticks, const Percept& percept)
{
	if (!goal->isFinished())
	{
		AntPercept antPercept(percept);
		goal->update(*this, ticks, antPercept);
	}
}

bool AntFollowPathAntTest::isGoalFinished() const
{
	return goal->isFinished();
}