#include "SimpleWorld.hpp"
#include "../Simulator.hpp"
#include "../agent/Ant.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../sim/nav/Node.hpp"
#include "../sim/nav/Edge.hpp"

#include <vector>
#include <memory>

// Christopher D. Canfield
// November 2013
// SimpleWorld.cpp

using cdc::SimpleWorld;
using cdc::GuiEventManager;
using cdc::Node;
using cdc::Edge;
using cdc::GridLocation;

using namespace std;

void createNavGraph(vector<Node>& navGraph);


SimpleWorld::SimpleWorld()
{
}

SimpleWorld::~SimpleWorld()
{
}


void SimpleWorld::create(GuiEventManager& eventManager)
{
	createNavGraph(navGraph);
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
				auto& endNode = navGraph[(row + 1) * nav_graph_columns + column];
				auto edge = make_shared<Edge>(startNode, endNode, 1);
				if (!startNode.edgeExists(edge))
				{
					startNode.addEdge(edge);
				}
			}
		}
	}
}