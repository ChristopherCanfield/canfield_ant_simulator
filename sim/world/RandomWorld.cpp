#include "RandomWorld.hpp"
#include "../Simulator.hpp"
#include "../agent/Ant.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../sim/nav/Node.hpp"
#include "../sim/nav/Edge.hpp"
#include "../sim/worldobject/AntFoodPile.hpp"
#include "../sim/worldobject/SolidObject.hpp"
#include "../sim/worldobject/AntHome.hpp"

#include <vector>
#include <memory>
#include <cassert>

// Christopher D. Canfield
// November 2013
// RandomWorld.cpp

using cdc::RandomWorld;
using cdc::GuiEventManager;
using cdc::Node;
using cdc::Edge;
using cdc::GridLocation;
using cdc::AntFoodPile;

using namespace sf;
using namespace std;

void createNavGraph(vector<Node>& navGraph);
void addFood(vector<Node>& navGraph, vector<AntFoodPile> antFoodPiles);
void addObstructions(vector<Node>& navGraph, vector<Sprite> obstructions);


RandomWorld::RandomWorld()
{
}

RandomWorld::~RandomWorld()
{
}


void RandomWorld::create(GuiEventManager& eventManager)
{
	createNavGraph(navGraph);
	addFood(navGraph, antFoodPiles);
	addObstructions(navGraph, obstructions);
}


void createNavGraph(vector<Node>& navGraph)
{
	const int nav_graph_rows = 20;
	const int nav_graph_columns = 20;
	navGraph.reserve(nav_graph_rows * nav_graph_rows);
	
	const int side_offset = 50;
	const int node_offset = 150;

	for (int row = 0; row < nav_graph_rows; ++row)
	{
		for (int column = 0; column < nav_graph_columns; ++column)
		{
			int pixelX = side_offset + (column * node_offset);
			int pixelY = side_offset + (row * node_offset);
			navGraph.push_back(Node(GridLocation(row, column), pixelX, pixelY));
		}
	}

	for (int row = 0; row < nav_graph_rows; ++row)
	{
		for (int column = 0; column < nav_graph_columns; ++column)
		{
			auto& startNode = navGraph[(row * nav_graph_columns) + column];
			if (row > 0)
			{
				auto& endNode = navGraph[(row - 1) * nav_graph_columns + column];
				auto edge = make_shared<Edge>(startNode, endNode, 1);
				if (!startNode.edgeExists(edge))
				{
					startNode.addEdge(edge);
				}
			}
			if (row < nav_graph_columns - 1)
			{
				auto& endNode = navGraph[(row + 1) * nav_graph_columns + column];
				auto edge = make_shared<Edge>(startNode, endNode, 1);
				if (!startNode.edgeExists(edge))
				{
					startNode.addEdge(edge);
				}
			}

			if (column > 0)
			{
				auto& endNode = navGraph[row * nav_graph_columns + column - 1];
				auto edge = make_shared<Edge>(startNode, endNode, 1);
				if (!startNode.edgeExists(edge))
				{
					startNode.addEdge(edge);
				}
			}
			if (column < nav_graph_columns - 1)
			{
				auto& endNode = navGraph[row * nav_graph_columns + column + 1];
				auto edge = make_shared<Edge>(startNode, endNode, 1);
				if (!startNode.edgeExists(edge))
				{
					startNode.addEdge(edge);
				}
			}
		}
	}
}

void addFood(vector<Node>& navGraph, vector<AntFoodPile> antFoodPiles)
{
	assert(false);
}

void addObstructions(vector<Node>& navGraph, vector<Sprite> obstructions)
{
	assert(false);
}