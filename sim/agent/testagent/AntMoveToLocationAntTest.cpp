#include "AntMoveToLocationAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"
#include "../../goal/AntMoveToLocation.hpp"
#include "../util/make_unique.hpp"

// Christopher D. Canfield
// November 2013
// AntMoveToLocationAntTest.cpp

using namespace cdc;


AntMoveToLocationAntTest::AntMoveToLocationAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, Node& target) :
	AntGoalTester(manager, home, navGraphHelper)
{
	goal = make_unique<AntMoveToLocation>(*this, target);
}

AntMoveToLocationAntTest::~AntMoveToLocationAntTest()
{
}

void AntMoveToLocationAntTest::update(long ticks, const Percept& percept)
{
	if (!goal->isFinished())
	{
		AntPercept antPercept(percept);
		goal->update(*this, ticks, antPercept);
	}
}

bool AntMoveToLocationAntTest::isGoalFinished() const
{
	return goal->isFinished();
}