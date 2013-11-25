#include "AntMoveToNodeAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"
#include "../../goal/AntMoveToNode.hpp"
#include "../util/make_unique.hpp"


// Christopher D. Canfield
// November 2013
// AntMoveToNodeAntTest.cpp

using namespace cdc;


AntMoveToNodeAntTest::AntMoveToNodeAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode, Node& target) :
	AntGoalTester(manager, home, navGraphHelper, startNode)
{
	goal = make_unique<AntMoveToNode>(*this, target, true);
}

AntMoveToNodeAntTest::~AntMoveToNodeAntTest()
{
}

void AntMoveToNodeAntTest::update(uint ticks, const Percept& percept)
{
	if (!goal->isFinished())
	{
		AntPercept antPercept(percept);
		goal->update(*this, ticks, antPercept);
	}
}

bool AntMoveToNodeAntTest::isGoalFinished() const
{
	return goal->isFinished();
}