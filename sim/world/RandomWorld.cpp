#include "RandomWorld.hpp"
#include "../Simulator.hpp"
#include "../agent/Ant.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../sim/nav/Node.hpp"
#include "../sim/nav/Edge.hpp"
#include "../sim/worldobject/AntFoodPile.hpp"
#include "../sim/worldobject/SolidObject.hpp"
#include "../sim/worldobject/AntHome.hpp"
#include "../util/Random.hpp"

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
using cdc::AntHome;
using cdc::Random;
using cdc::SolidObject;

using namespace sf;
using namespace std;

// Creates the world's navigation graph.
void createNavGraph(vector<Node>& navGraph);

// Adds food piles to the world.
void addFood(vector<Node>& navGraph, vector<Node*>& occupiedAreas, vector<AntFoodPile>& antFoodPiles);

// Adds obstructions to the world.
void addObstructions(vector<Node>& navGraph, vector<Node*>& occupiedAreas, vector<Sprite>& obstructions);

// Adds the ant hill to the world.
// Returns the ant hill location within the nav graph.
int addAntHill(vector<Node>& navGraph, vector<Node*>& occupiedAreas, vector<AntHome>& antHills);

// Adds a random number of ants to the world.
void addAnts(vector<Node>& navGraph, AntHome& antHill, int antHillNodeLocation);

// Returns true if the node is occupied, or false if not.
bool isOccupied(vector<Node*> occupiedAreas, Node& location);


// TODO: the size of the world should be accessible outside of the class,
// or the size should be passed into the world.
const int nav_graph_rows = 30;
const int nav_graph_columns = 30;

const int side_offset = 50;
const int node_offset = 100;


RandomWorld::RandomWorld()
{
}

RandomWorld::~RandomWorld()
{
}


void RandomWorld::create(GuiEventManager& eventManager)
{
	createNavGraph(navGraph);
	vector<Node*> offLimitAreas;

	addFood(navGraph, offLimitAreas, antFoodPiles);
	addObstructions(navGraph, offLimitAreas, obstructions);
	int antHillLocation = addAntHill(navGraph, offLimitAreas, antHills);
	addAnts(navGraph, antHills[0], antHillLocation);
}


void createNavGraph(vector<Node>& navGraph)
{
	navGraph.reserve(nav_graph_rows * nav_graph_rows);

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

void addFood(vector<Node>& navGraph, vector<Node*>& occupiedAreas, vector<AntFoodPile>& antFoodPiles)
{
	assert(false);
}

void addObstructions(vector<Node>& navGraph, vector<Node*>& occupiedAreas, vector<Sprite>& obstructions)
{
	Random rand;

	// Add between 10 and 20 obstructions.
	const int maxObstructions = 20;
	const int minObstructions = 10;

	int obstructionCount = rand.getInteger(minObstructions, maxObstructions);
	for (int i = 0; i < maxObstructions; ++i)
	{
		bool validLocationFound = false;
		while (!validLocationFound)
		{
			int nodeLocation = rand.getInteger(0, navGraph.size() - 1);
			if (!isOccupied(occupiedAreas, navGraph[nodeLocation]))
			{
				validLocationFound = true;
				auto rock = SolidObject::createRock(navGraph, navGraph[nodeLocation].getPixelX(), navGraph[nodeLocation].getPixelY());
				obstructions.push_back(rock);
				occupiedAreas.push_back(&navGraph[nodeLocation]);
			}
		}
	}
}

int addAntHill(vector<Node>& navGraph, vector<Node*>& occupiedAreas, vector<AntHome>& antHills)
{
	Random rand;

	bool validLocationFound = false;
	while (!validLocationFound)
	{
		// Ant hill can be in any node within the first three rows.
		int antHillLocation = rand.getInteger(0, 3 * nav_graph_columns);
		if (!isOccupied(occupiedAreas, navGraph[antHillLocation]))
		{
			antHills.push_back(AntHome(navGraph[antHillLocation]));
			occupiedAreas.push_back(&navGraph[antHillLocation]);
			return antHillLocation;
		}
	}
}

void addAnts(vector<Node>& navGraph, AntHome& antHill, int antHillNodeLocation)
{
	Random rand;


}

bool isOccupied(vector<Node*> occupiedAreas, Node& location)
{
	for (auto& occupied : occupiedAreas)
	{
		if (occupied == &location)
		{
			return true;
		}
	}
	return false;
}