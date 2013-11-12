#include "AntExploreAntTest.hpp"
#include "../../nav/Node.hpp"
#include "../../nav/NavGraphHelper.hpp"
#include "../../worldobject/AntHome.hpp"
#include "../../goal/AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntExploreAntTest.cpp

using namespace cdc;


AntExploreAntTest::AntExploreAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper) :
	Ant(manager, home, navGraphHelper)
{
}

AntExploreAntTest::~AntExploreAntTest()
{
}

void AntExploreAntTest::update(long ticks, const Percept& percept)
{

}



