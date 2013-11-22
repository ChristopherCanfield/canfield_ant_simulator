#include "AntEatAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"
#include "../../goal/AntEat.hpp"
#include "../util/make_unique.hpp"

#include <cassert>
#include <iostream>

// Christopher D. Canfield
// November 2013
// AntEatAntTest.cpp

using namespace std;
using namespace cdc;


AntEatAntTest::AntEatAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode) :
	AntGoalTester(manager, home, navGraphHelper, startNode)
{
	goal = make_unique<AntEat>();
}

AntEatAntTest::~AntEatAntTest()
{
}

void AntEatAntTest::update(long ticks, const Percept& percept)
{
	cout << "AntEatAntTest::update is not implemented" << endl;
	assert(false);
}

bool AntEatAntTest::isGoalFinished() const
{
	return goal->isFinished();
}


