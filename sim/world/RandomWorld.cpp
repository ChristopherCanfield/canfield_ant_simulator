#include "RandomWorld.hpp"
#include "../Simulator.hpp"
#include "../agent/Ant.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../sim/nav/Node.hpp"
#include "../sim/nav/Edge.hpp"
#include "../sim/agent/Ant.hpp"
#include "../sim/worldobject/AntFoodPile.hpp"
#include "../sim/worldobject/SolidObject.hpp"
#include "../sim/worldobject/AntHome.hpp"
#include "../util/Random.hpp"
#include "../util/make_unique.hpp"

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
using cdc::Ant;
using cdc::World;

using namespace sf;
using namespace std;

// Creates the world's navigation graph.
void createNavGraph(vector<Node>& navGraph);
void addConnections(vector<vector<Node*>>& navGraphEdgeHelper);

// Adds food piles to the world.
void addFood(vector<Node>& navGraph, vector<Node*>& occupiedAreas, vector<unique_ptr<AntFoodPile>>& antFoodPiles);

// Adds obstructions to the world.
void addObstructions(vector<Node>& navGraph, vector<Node*>& occupiedAreas, vector<Sprite>& obstructions);

// Adds the ant hill to the world.
void addAntHill(World& world, vector<Node>& navGraph, vector<Node*>& occupiedAreas, vector<unique_ptr<AntHome>>& antHills);

// Adds a random number of ants to the world.
void addAnts(AntHome& antHill, GuiEventManager& eventManager, vector<unique_ptr<Ant>>& ants);

// Finds an unoccupied location between the min and max node (inclusive).
// Returns the index of the node within the nav graph.
int findValidLocation(vector<Node>& navGraph, vector<Node*>& occupiedAreas, int minAllowedNode, int maxAllowedNode, Random& rand);

// Returns true if the node is occupied, or false if not.
bool isOccupied(vector<Node*> occupiedAreas, Node& location);


// TODO: the size of the world should be accessible outside of the class,
// or the size should be passed into the world.
const int navGraphRows = 30;
const int navGraphColumns = 30;

const int sideOffset = 50;
const int nodeOffset = 100;


RandomWorld::RandomWorld()
{
}

RandomWorld::~RandomWorld()
{
}


void RandomWorld::create(GuiEventManager& eventManager)
{
	this->eventManager = &eventManager;
	createNavGraph(navGraph);
	vector<Node*> offLimitAreas;

	addFood(navGraph, offLimitAreas, antFoodPiles);
	addObstructions(navGraph, offLimitAreas, obstructions);
	addAntHill(*this, navGraph, offLimitAreas, antHills);
	addAnts(*antHills[0], eventManager, ants);
}


void createNavGraph(vector<Node>& navGraph)
{
	navGraph.reserve(navGraphRows * navGraphColumns);
	vector<vector<Node*>> navGraphEdgeHelper(navGraphRows, vector<Node*>(navGraphColumns, nullptr));

	for (int row = 0; row < navGraphRows; ++row)
	{
		for (int column = 0; column < navGraphColumns; ++column)
		{
			int pixelX = sideOffset + (column * nodeOffset);
			int pixelY = sideOffset + (row * nodeOffset);
			navGraph.push_back(Node(GridLocation(row, column), pixelX, pixelY));
			navGraphEdgeHelper[row][column] = &navGraph.back();
		}
	}

	addConnections(navGraphEdgeHelper);
}

void addConnections(vector<vector<Node*>>& navGraphEdgeHelper)
{
	for (int row = 0; row < navGraphRows; ++row)
	{
		for (int column = 0; column < navGraphColumns; ++column)
		{
			auto& startNode = *navGraphEdgeHelper[row][column];
			// Add up connection.
			if (row > 0)
			{
				auto& endNode = *navGraphEdgeHelper[row - 1][column];
				auto edge = make_shared<Edge>(startNode, endNode, 1);
				if (!startNode.edgeExists(edge))
				{
					startNode.addEdge(edge);
				}
			}
			// Add down connection.
			if (row < navGraphColumns - 1)
			{
				auto& endNode = *navGraphEdgeHelper[row + 1][column];
				auto edge = make_shared<Edge>(startNode, endNode, 1);
				if (!startNode.edgeExists(edge))
				{
					startNode.addEdge(edge);
				}
			}
			// Add left connection.
			if (column > 0)
			{
				auto& endNode = *navGraphEdgeHelper[row][column - 1];
				auto edge = make_shared<Edge>(startNode, endNode, 1);
				if (!startNode.edgeExists(edge))
				{
					startNode.addEdge(edge);
				}
			}
			// Add right connection.
			if (column < navGraphColumns - 1)
			{
				auto& endNode = *navGraphEdgeHelper[row][column + 1];
				auto edge = make_shared<Edge>(startNode, endNode, 1);
				if (!startNode.edgeExists(edge))
				{
					startNode.addEdge(edge);
				}
			}
			// Add diagonal connections
			if (row > 0 && row < (navGraphRows - 1) && column > 0 && column < (navGraphColumns - 1))
			{
				auto& diagonal1Node = *navGraphEdgeHelper[row + 1][column - 1];
				auto edge1 = make_shared<Edge>(startNode, diagonal1Node, 1);
				
				auto& diagonal2Node = *navGraphEdgeHelper[row + 1][column + 1];
				auto edge2 = make_shared<Edge>(startNode, diagonal2Node, 1);

				auto& diagonal3Node = *navGraphEdgeHelper[row - 1][column - 1];
				auto edge3 = make_shared<Edge>(startNode, diagonal3Node, 1);

				auto& diagonal4Node = *navGraphEdgeHelper[row - 1][column + 1];
				auto edge4 = make_shared<Edge>(startNode, diagonal4Node, 1);

				if (!startNode.edgeExists(edge1))
				{
					startNode.addEdge(edge1);
				}
				if (!startNode.edgeExists(edge2))
				{
					startNode.addEdge(edge2);
				}
				if (!startNode.edgeExists(edge3))
				{
					startNode.addEdge(edge3);
				}
				if (!startNode.edgeExists(edge4))
				{
					startNode.addEdge(edge4);
				}
			}
		}
	}

	// Add diagonal connections to corners.
	auto& node_0_1 = *navGraphEdgeHelper[0][1];
	auto edge1 = make_shared<Edge>(node_0_1, *navGraphEdgeHelper[1][0], 1);
	node_0_1.addEdge(edge1);
				
	auto& node_0_last = *navGraphEdgeHelper[0][navGraphColumns - 2];
	auto edge2 = make_shared<Edge>(node_0_last, *navGraphEdgeHelper[1][navGraphColumns - 1], 1);
	node_0_last.addEdge(edge2);

	auto& node_last2_0 = *navGraphEdgeHelper[navGraphRows - 2][0];
	auto edge3 = make_shared<Edge>(node_last2_0, *navGraphEdgeHelper[navGraphRows - 1][1], 1);
	node_last2_0.addEdge(edge3);

	auto& node_last_last2 = *navGraphEdgeHelper[navGraphRows - 1][navGraphColumns - 2];
	auto edge4 = make_shared<Edge>(node_last_last2, *navGraphEdgeHelper[navGraphRows - 2][navGraphColumns - 1], 1);
	node_last_last2.addEdge(edge4);
}

void addFood(vector<Node>& navGraph, vector<Node*>& occupiedAreas, vector<unique_ptr<AntFoodPile>>& antFoodPiles)
{
	Random rand;

	// Add between 3 and 15 piles of food.
	const int minFoodPiles = 3;
	const int maxFoodPiles = 15;

	int foodPileCount = rand.getInteger(minFoodPiles, maxFoodPiles);
	for (int i = 0; i < foodPileCount; ++i)
	{
		int nodeLocation = findValidLocation(navGraph, occupiedAreas, 0, navGraph.size() - 1, rand);
		int foodInPile = rand.getInteger(50, 750);
		antFoodPiles.push_back(make_unique<AntFoodPile>(foodInPile, navGraph[nodeLocation]));
		occupiedAreas.push_back(&navGraph[nodeLocation]);
	}
}

void addObstructions(vector<Node>& navGraph, vector<Node*>& occupiedAreas, vector<Sprite>& obstructions)
{
	Random rand;

	// Add between 10 and 50 obstructions.
	const int maxObstructions = 50;
	const int minObstructions = 10;

	int obstructionCount = rand.getInteger(minObstructions, maxObstructions);
	for (int i = 0; i < obstructionCount; ++i)
	{
		int nodeLocation = findValidLocation(navGraph, occupiedAreas, 0, navGraph.size() - 1, rand);
		auto rock = SolidObject::createRock(navGraph, navGraph[nodeLocation].getPixelX<int>(), navGraph[nodeLocation].getPixelY<int>());
		obstructions.push_back(rock);
		occupiedAreas.push_back(&navGraph[nodeLocation]);
	}
}

void addAntHill(World& world, vector<Node>& navGraph, vector<Node*>& occupiedAreas, vector<unique_ptr<AntHome>>& antHills)
{
	Random rand;

	// Ant hill can be in any node within the first three rows.
	int nodeLocation = findValidLocation(navGraph, occupiedAreas, 0, 3 * navGraphColumns, rand);
	
	antHills.push_back(make_unique<AntHome>(navGraph[nodeLocation], navGraph, world));
	occupiedAreas.push_back(&navGraph[nodeLocation]);
}

void addAnts(AntHome& antHill, GuiEventManager& eventManager, vector<unique_ptr<Ant>>& ants)
{
	Random rand;

	const int minAnts = 30;
	const int maxAnts = 60;

	int antCount = rand.getInteger(minAnts, maxAnts);
	for (int i = 0; i < antCount; ++i)
	{
		ants.push_back(make_unique<Ant>(eventManager, antHill, antHill.getNavGraphHelper(), antHill.getNode()));
	}
}

int findValidLocation(vector<Node>& navGraph, vector<Node*>& occupiedAreas, int minAllowedNode, int maxAllowedNode, Random& rand)
{
	bool validLocationFound = false;
	while (!validLocationFound)
	{
		int nodeLocation = rand.getInteger(minAllowedNode, maxAllowedNode);
		if (!isOccupied(occupiedAreas, navGraph[nodeLocation]))
		{
			return nodeLocation;
		}
	}
	return -1;
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