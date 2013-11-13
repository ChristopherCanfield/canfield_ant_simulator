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


AntEatAntTest::AntEatAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper) :
	AntGoalTester(manager, home, navGraphHelper)
{
	goal = make_unique<AntEat>();
}

AntEatAntTest::~AntEatAntTest()
{
}

void AntEatAntTest::update(long ticks, const Percept& percept)
{

}

bool AntEatAntTest::isGoalFinished() const
{
	return goal->isFinished();
}


