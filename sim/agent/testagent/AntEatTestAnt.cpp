#include "AntEatTestAnt.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntEatTestAnt.cpp

using namespace cdc;


AntEatTestAnt::AntEatTestAnt(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper) :
	Ant(manager, home, navGraphHelper)
{
}

AntEatTestAnt::~AntEatTestAnt()
{
}

void AntEatTestAnt::update(long ticks, const Percept& percept)
{

}



