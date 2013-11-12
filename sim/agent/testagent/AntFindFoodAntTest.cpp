#include "AntFindFoodAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntFindFoodAntTest.cpp

using namespace cdc;


AntFindFoodAntTest::AntFindFoodAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper) :
	Ant(manager, home, navGraphHelper)
{
}

AntFindFoodAntTest::~AntFindFoodAntTest()
{
}

void AntFindFoodAntTest::update(long ticks, const Percept& percept)
{

}



