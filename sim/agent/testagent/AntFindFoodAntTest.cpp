#include "AntFindFoodAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"
#include "../../goal/AntFindFood.hpp"
#include "../util/make_unique.hpp"

// Christopher D. Canfield
// November 2013
// AntFindFoodAntTest.cpp

using namespace cdc;


AntFindFoodAntTest::AntFindFoodAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode) :
	AntGoalTester(manager, home, navGraphHelper, startNode)
{
	goal = make_unique<AntFindFood>();
}

AntFindFoodAntTest::~AntFindFoodAntTest()
{
}

void AntFindFoodAntTest::update(long ticks, const Percept& percept)
{

}

bool AntFindFoodAntTest::isGoalFinished() const
{
	return goal->isFinished();
}


