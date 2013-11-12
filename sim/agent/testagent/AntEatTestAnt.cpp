#include "AntEatTestAnt.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"
#include "../../goal/AntEat.hpp"
#include "../util/make_unique.hpp"

// Christopher D. Canfield
// November 2013
// AntEatTestAnt.cpp

using namespace cdc;


AntEatTestAnt::AntEatTestAnt(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper) :
	AntGoalTester(manager, home, navGraphHelper)
{
	goal = make_unique<AntEat>();
}

AntEatTestAnt::~AntEatTestAnt()
{
}

void AntEatTestAnt::update(long ticks, const Percept& percept)
{

}

bool AntEatTestAnt::isGoalFinished() const
{
	return goal->isFinished();
}


