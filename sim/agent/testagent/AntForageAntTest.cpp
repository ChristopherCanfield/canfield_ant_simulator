#include "AntForageAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntForageAntTest.cpp

using namespace cdc;


AntForageAntTest::AntForageAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper) :
	Ant(manager, home, navGraphHelper)
{
}

AntForageAntTest::~AntForageAntTest()
{
}

void AntForageAntTest::update(long ticks, const Percept& percept)
{

}



