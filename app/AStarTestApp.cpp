#include "AStarTestApp.hpp"

#include "../sim/nav/Node.hpp"
#include "../sim/nav/Edge.hpp"
#include "../sim/nav/PathNode.hpp"
#include "../sim/nav/Search.hpp"

// Christopher D. Canfield
// November 2013
// AStarTestApp.cpp

using namespace cdc;
using namespace std;


vector<Node> createNavGraph1();


AStarTestApp::AStarTestApp()
{
}


void AStarTestApp::setup()
{
}

bool AStarTestApp::run()
{
	vector<Node> navGraph = createNavGraph1();
	auto path = Search::aStar(navGraph[0], navGraph[7], navGraph, Search::straightLineHeuristic, true);
	return true;
}

void AStarTestApp::teardown() 
{
}

vector<Node> createNavGraph1()
{
	vector<Node> navGraph;
	navGraph.push_back(Node(GridLocation(0, 0), 10, 20));	// 0
	navGraph.push_back(Node(GridLocation(0, 1), 10, 20));	// 1
	navGraph.push_back(Node(GridLocation(0, 2), 10, 20));	// 2
	navGraph.push_back(Node(GridLocation(0, 3), 10, 20));	// 3
	navGraph.push_back(Node(GridLocation(1, 0), 10, 20));	// 4
	navGraph.push_back(Node(GridLocation(1, 1), 10, 20));	// 5
	navGraph.push_back(Node(GridLocation(1, 2), 10, 20));	// 6
	navGraph.push_back(Node(GridLocation(1, 3), 10, 20));	// 7
	navGraph.push_back(Node(GridLocation(2, 0), 10, 20));	// 8
	navGraph.push_back(Node(GridLocation(2, 1), 10, 20));	// 9
	navGraph.push_back(Node(GridLocation(2, 2), 10, 20));	// 10
	navGraph.push_back(Node(GridLocation(2, 3), 10, 20));	// 11

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

	return navGraph;
}