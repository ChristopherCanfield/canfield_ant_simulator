#include "AntGoHomeAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"
#include "../../goal/AntGoHome.hpp"
#include "../util/make_unique.hpp"

#include <cassert>
#include <iostream>

// Christopher D. Canfield
// November 2013
// AntGoHomeAntTest.cpp

using namespace std;
using namespace cdc;


AntGoHomeAntTest::AntGoHomeAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode) :
	AntGoalTester(manager, home, navGraphHelper, startNode)
{
	goal = make_unique<AntGoHome>();
}

AntGoHomeAntTest::~AntGoHomeAntTest()
{
}

void AntGoHomeAntTest::update(long ticks, const Percept& percept)
{
	cout << "AntGoHomeAntTest::update is not implemented" << endl;
	assert(false);
}

bool AntGoHomeAntTest::isGoalFinished() const
{
	return goal->isFinished();
}

