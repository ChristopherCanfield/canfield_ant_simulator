#include "AntGoHomeAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"
#include "../../goal/AntGoHome.hpp"
#include "../util/make_unique.hpp"


// Christopher D. Canfield
// November 2013
// AntGoHomeAntTest.cpp

using namespace cdc;


AntGoHomeAntTest::AntGoHomeAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode) :
	AntGoalTester(manager, home, navGraphHelper, startNode)
{
	goal = make_unique<AntGoHome>();
}

AntGoHomeAntTest::~AntGoHomeAntTest()
{
}

void AntGoHomeAntTest::update(uint ticks, const Percept& percept)
{
	if (!goal->isFinished())
	{
		AntPercept antPercept(percept);
		goal->update(*this, ticks, antPercept);
	}
}

bool AntGoHomeAntTest::isGoalFinished() const
{
	return goal->isFinished();
}

