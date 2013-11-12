#include "AntMoveToLocationAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntMoveToLocationAntTest.cpp

using namespace cdc;


AntMoveToLocationAntTest::AntMoveToLocationAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper) :
	Ant(manager, home, navGraphHelper)
	
{
}

AntMoveToLocationAntTest::~AntMoveToLocationAntTest()
{
}

void AntMoveToLocationAntTest::update(long ticks, const Percept& percept)
{

}
