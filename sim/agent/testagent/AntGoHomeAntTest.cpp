#include "AntGoHomeAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntGoHomeAntTest.cpp

using namespace cdc;


AntGoHomeAntTest::AntGoHomeAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper) :
	Ant(manager, home, navGraphHelper)
{
}

AntGoHomeAntTest::~AntGoHomeAntTest()
{
}

void AntGoHomeAntTest::update(long ticks, const Percept& percept)
{

}



