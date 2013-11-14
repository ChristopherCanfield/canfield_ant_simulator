#include "AntFollowPathAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"
#include "../../goal/AntMoveToNode.hpp"
#include "../util/make_unique.hpp"

#include <cassert>

// Christopher D. Canfield
// November 2013
// AntFollowPathAntTest.cpp

using namespace cdc;


AntFollowPathAntTest::AntFollowPathAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode) :
	AntGoalTester(manager, home, navGraphHelper, startNode)
{
	//goal = make_unique<AntMoveToNode>(*this, target, true);
}

AntFollowPathAntTest::~AntFollowPathAntTest()
{
}

void AntFollowPathAntTest::update(long ticks, const Percept& percept)
{
	// TODO: implement this.
	assert(false);
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