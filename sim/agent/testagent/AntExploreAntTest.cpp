#include "AntExploreAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"
#include "../../goal/AntExplore.hpp"
#include "../util/make_unique.hpp"


// Christopher D. Canfield
// November 2013
// AntExploreAntTest.cpp

using namespace cdc;


AntExploreAntTest::AntExploreAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode) :
	AntGoalTester(manager, home, navGraphHelper, startNode)
{
	goal = make_unique<AntExplore>();
}

AntExploreAntTest::~AntExploreAntTest()
{
}

void AntExploreAntTest::update(long ticks, const Percept& percept)
{
	if (!goal->isFinished())
	{
		AntPercept antPercept(percept);
		goal->update(*this, ticks, antPercept);
	}
}

bool AntExploreAntTest::isGoalFinished() const
{
	return goal->isFinished();
}

