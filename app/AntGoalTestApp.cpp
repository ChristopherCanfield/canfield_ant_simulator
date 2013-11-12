#include "AntGoalTestApp.hpp"
#include "../sim/agent/testagent/AntGoalTester.hpp"

#include <iostream>


// Christopher D. Canfield
// November 2013
// AntGoalTestApp.cpp

using namespace std;
using namespace cdc;


AntGoalTestApp::AntGoalTestApp() :
	viewManager(eventManager, 1000, 1000, 800, 800, 200, 800)
{
}


AntGoalTestApp::~AntGoalTestApp()
{
}

void AntGoalTestApp::setup()
{
	cout << "Ant goal tester type: " << endl;
	cout << "  1: AntEat" << endl;
	cout << "  2: AntExplore" << endl;
	cout << "  3: AntFindFood" << endl;
	cout << "  4: AntForage" << endl;
	cout << "  5: AntGoHome" << endl;
	cout << "  6: AntMoveToLocation" << endl;
}

bool AntGoalTestApp::run()
{
	return false;
}

void AntGoalTestApp::teardown()
{

}