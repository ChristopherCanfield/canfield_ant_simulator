#include "AntGoalTestApp.hpp"
#include "../sim/worldobject/AntHome.hpp"
#include "../sim/nav/Node.hpp"
#include "../sim/agent/testagent/AntGoalTester.hpp"
#include "../sim/agent/testagent/AntEatAntTest.hpp"
#include "../sim/agent/testagent/AntExploreAntTest.hpp"
#include "../sim/agent/testagent/AntFindFoodAntTest.hpp"
#include "../sim/agent/testagent/AntForageAntTest.hpp"
#include "../sim/agent/testagent/AntGoHomeAntTest.hpp"
#include "../sim/agent/testagent/AntMoveToNodeAntTest.hpp"
#include "../sim/agent/testagent/AntFollowPathAntTest.hpp"
#include "../util/make_unique.hpp"
#include "../sim/knowledge/GenericPercept.hpp"

#include <iostream>
#include <vector>


// Christopher D. Canfield
// November 2013
// AntGoalTestApp.cpp

using namespace std;
using namespace cdc;

void createNavGraph1(vector<Node>& navGraph);
std::vector<unique_ptr<AntGoalTester>> getTestAnts(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, 
									 Node& startNode, Node& nearTarget, Node& farTarget);


AntGoalTestApp::AntGoalTestApp() :
	viewManager(eventManager, 1000, 1000, 800, 800, 200, 800),
	ticks(0)
{
}


AntGoalTestApp::~AntGoalTestApp()
{
}

void AntGoalTestApp::setup()
{
	createNavGraph1(navGraph);
	foodPile = new AntFoodPile(100, navGraph[11]);
	navGraphHelper = NavGraphHelper(navGraph);

	antHome = new AntHome(navGraph[10], navGraph, world);
	goalTestAnts = getTestAnts(eventManager, *antHome, navGraphHelper, navGraph[0], navGraph[1], navGraph.back());

	window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(800, 800), "GUI Tests"));
	window->setFramerateLimit(60);

	viewManager.setWindow(*window);
	viewManager.getSimView().setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
}

bool AntGoalTestApp::run()
{
	if (ant != nullptr && ant->isGoalFinished() && goalTestAnts.empty())
	{
		return false;
	}

	if (ant == nullptr || ant->isGoalFinished())
	{
		ant = move(goalTestAnts.back());
		goalTestAnts.pop_back();
		cout << "----------------------------------------" << endl;
		cout << "Running ant test: " << (typeid(*ant.get()).name()) << endl;
		cout << "----------------------------------------" << endl;
	}

	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
			return false;
		}
		else
		{
			eventManager.update(event, *window);
		}
	}

	GenericPercept percept;
	ant->update(ticks, percept);
	++ticks;

	window->clear(sf::Color::Green);

	for (auto& node : navGraph)
	{
		window->draw(node);
	}
	for (auto& node : navGraph)
	{
		for (auto& edge : node.getEdgeList())
		{
			edge->drawPheromone(*window, sf::RenderStates::Default);
		}
	}

	window->draw(*ant);
	window->draw(*foodPile);

	window->display();

	return true;
}

void AntGoalTestApp::teardown()
{

}

std::vector<unique_ptr<AntGoalTester>> getTestAnts(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, 
									 Node& startNode, Node& nearTarget, Node& farTarget)
{
	cout << "Ant goal tester type: " << endl;
	cout << "  1: AntEat" << endl;
	cout << "  2: AntExplore" << endl;
	cout << "  3: AntFindFood" << endl;
	cout << "  4: AntForage" << endl;
	cout << "  5: AntGoHome" << endl;
	cout << "  6: AntMoveToNode" << endl;
	cout << "  7: AntFollowPath" << endl;
	cout << "  8: Run all tests" << endl;
	cout << "Type: ";

	int goalType;
	cin >> goalType;

	std::vector<unique_ptr<AntGoalTester>> goals;

	switch (goalType)
	{
	case 1:
		goals.push_back(make_unique<AntEatAntTest>(manager, home, navGraphHelper, startNode));
		break;
	case 2:
		goals.push_back(make_unique<AntExploreAntTest>(manager, home, navGraphHelper, startNode));
		break;
	case 3:
		goals.push_back(make_unique<AntFindFoodAntTest>(manager, home, navGraphHelper, startNode));
		break;
	case 4:
		goals.push_back(make_unique<AntForageAntTest>(manager, home, navGraphHelper, startNode));
		break;
	case 5:
		goals.push_back(make_unique<AntGoHomeAntTest>(manager, home, navGraphHelper, startNode));
		break;
	case 6:
		goals.push_back(make_unique<AntMoveToNodeAntTest>(manager, home, navGraphHelper, startNode, nearTarget));
		break;
	case 7:
		goals.push_back(make_unique<AntFollowPathAntTest>(manager, home, navGraphHelper, startNode, farTarget));
		break;
	case 8:
		goals.push_back(make_unique<AntEatAntTest>(manager, home, navGraphHelper, startNode));
		goals.push_back(make_unique<AntExploreAntTest>(manager, home, navGraphHelper, startNode));
		goals.push_back(make_unique<AntFindFoodAntTest>(manager, home, navGraphHelper, startNode));
		goals.push_back(make_unique<AntForageAntTest>(manager, home, navGraphHelper, startNode));
		goals.push_back(make_unique<AntGoHomeAntTest>(manager, home, navGraphHelper, startNode));
		goals.push_back(make_unique<AntMoveToNodeAntTest>(manager, home, navGraphHelper, startNode, nearTarget));
		goals.push_back(make_unique<AntFollowPathAntTest>(manager, home, navGraphHelper, startNode, farTarget));
		break;
	default:
		throw runtime_error("Invalid goal selection");
	}

	return goals;
}

void createNavGraph1(vector<Node>& navGraph)
{
	navGraph.reserve(12);
	navGraph.push_back(Node(GridLocation(0, 0), 50, 50));	// 0
	navGraph.push_back(Node(GridLocation(0, 1), 150, 50));	// 1
	navGraph.push_back(Node(GridLocation(0, 2), 250, 50));	// 2
	navGraph.push_back(Node(GridLocation(0, 3), 350, 50));	// 3
	navGraph.push_back(Node(GridLocation(1, 0), 50, 150));	// 4
	navGraph.push_back(Node(GridLocation(1, 1), 150, 150));	// 5
	navGraph.push_back(Node(GridLocation(1, 2), 250, 150));	// 6
	navGraph.push_back(Node(GridLocation(1, 3), 350, 150));	// 7
	navGraph.push_back(Node(GridLocation(2, 0), 50, 250));	// 8
	navGraph.push_back(Node(GridLocation(2, 1), 150, 250));	// 9
	navGraph.push_back(Node(GridLocation(2, 2), 250, 250));	// 10
	navGraph.push_back(Node(GridLocation(2, 3), 350, 250));	// 11

	auto edge_00_01 = make_shared<Edge>(navGraph[0], navGraph[1], 1);
	auto edge_00_10 = make_shared<Edge>(navGraph[0], navGraph[4], 1);
	navGraph[0].addEdge(edge_00_01).addEdge(edge_00_10);
			
	auto edge_01_02 = make_shared<Edge>(navGraph[1], navGraph[2], 1);
	auto edge_01_11 = make_shared<Edge>(navGraph[1], navGraph[5], 1);
	navGraph[1].addEdge(edge_01_02).addEdge(edge_01_11);

	auto edge_02_03 = make_shared<Edge>(navGraph[2], navGraph[3], 1);
	auto edge_02_12 = make_shared<Edge>(navGraph[2], navGraph[6], 1);
	navGraph[2].addEdge(edge_02_03).addEdge(edge_02_12);

	auto edge_03_13 = make_shared<Edge>(navGraph[3], navGraph[7], 1);
	navGraph[3].addEdge(edge_03_13);

	auto edge_10_11 = make_shared<Edge>(navGraph[4], navGraph[5], 1);
	auto edge_10_20 = make_shared<Edge>(navGraph[4], navGraph[8], 1);
	navGraph[4].addEdge(edge_10_11).addEdge(edge_10_20);

	auto edge_11_12 = make_shared<Edge>(navGraph[5], navGraph[6], 1);
	auto edge_11_21 = make_shared<Edge>(navGraph[5], navGraph[9], 1);
	navGraph[5].addEdge(edge_11_12).addEdge(edge_11_21);

	auto edge_12_13 = make_shared<Edge>(navGraph[6], navGraph[7], 1);
	auto edge_12_22 = make_shared<Edge>(navGraph[6], navGraph[10], 1);
	navGraph[6].addEdge(edge_12_13).addEdge(edge_12_22);

	auto edge_13_23 = make_shared<Edge>(navGraph[7], navGraph[11], 1);
	navGraph[7].addEdge(edge_13_23);

	auto edge_20_21 = make_shared<Edge>(navGraph[8], navGraph[9], 1);
	navGraph[8].addEdge(edge_20_21);

	auto edge_21_22 = make_shared<Edge>(navGraph[9], navGraph[10], 1);
	navGraph[9].addEdge(edge_21_22);

	auto edge_22_23 = make_shared<Edge>(navGraph[10], navGraph[11], 1);
	navGraph[10].addEdge(edge_22_23);
}