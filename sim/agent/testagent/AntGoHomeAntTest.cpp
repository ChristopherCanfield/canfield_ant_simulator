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


AntGoHomeAntTest::AntGoHomeAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper) :
	AntGoalTester(manager, home, navGraphHelper)
{
	goal = make_unique<AntGoHome>();
}

AntGoHomeAntTest::~AntGoHomeAntTest()
{
}

void AntGoHomeAntTest::update(long ticks, const Percept& percept)
{

}

bool AntGoHomeAntTest::isGoalFinished() const
{
	return goal->isFinished();
}

