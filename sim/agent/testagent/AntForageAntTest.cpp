#include "AntForageAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"
#include "../../goal/AntForage.hpp"
#include "../util/make_unique.hpp"

// Christopher D. Canfield
// November 2013
// AntForageAntTest.cpp

using namespace cdc;


AntForageAntTest::AntForageAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode) :
	AntGoalTester(manager, home, navGraphHelper, startNode)
{
	goal = make_unique<AntForage>();
}

AntForageAntTest::~AntForageAntTest()
{
}

void AntForageAntTest::update(long ticks, const Percept& percept)
{
	if (!goal->isFinished())
	{
		AntPercept antPercept(percept);
		goal->update(*this, ticks, antPercept);
	}
}

bool AntForageAntTest::isGoalFinished() const
{
	return goal->isFinished();
}


