#include "AntEatAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"
#include "../../goal/AntEat.hpp"
#include "../util/make_unique.hpp"


// Christopher D. Canfield
// November 2013
// AntEatAntTest.cpp

using namespace cdc;


AntEatAntTest::AntEatAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode) :
	AntGoalTester(manager, home, navGraphHelper, startNode)
{
	goal = make_unique<AntEat>();
}

AntEatAntTest::~AntEatAntTest()
{
}

void AntEatAntTest::update(uint ticks, const Percept& percept)
{
	if (!goal->isFinished())
	{
		AntPercept antPercept(percept);
		goal->update(*this, ticks, antPercept);
	}
}

bool AntEatAntTest::isGoalFinished() const
{
	return goal->isFinished();
}


