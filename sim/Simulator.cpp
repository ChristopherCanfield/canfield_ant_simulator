#include "Simulator.hpp"
#include "world/World.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../sim/knowledge/GenericPercept.hpp"

#include <iostream>
#include <algorithm>


// Christopher D. Canfield
// October 2013
// Simulator.hpp

using cdc::Simulator;
using cdc::World;
using cdc::GuiEventManager;
using cdc::Ant;

using namespace std;


uint maxSimSpeed = 120;
uint minSimSpeed = 0;
uint simSpeedIncrement = 10;

const uint Simulator::defaultTicksPerSecond = 60;

// Returns the selected ant, if there is one, or nullptr.
const Ant* getSelectedAnt(const vector<unique_ptr<Ant>>& ants);
// Returns a count of the live ants.
uint getLiveAntCount(World& world);


Simulator::Simulator(GuiEventManager& eventManager) :
	eventManager(eventManager),
	started(false),
	speed(defaultTicksPerSecond),
	displayPheromones(false),
	displayNavGraph(false),
	displayDeadAnts(true),
	displayAntPaths(false),
	ticks(0)
{
}


Simulator::~Simulator()
{
}


void Simulator::update()
{
	sf::Int32 speedMilliseconds = 1000 / speed;
	if (started && (clock.getElapsedTime().asMilliseconds() >= speedMilliseconds))
	{
		for (auto& node : world->getNavGraph())
		{
			node.update(ticks);
		}

		GenericPercept percept;
		for (auto& ant : world->getAnts())
		{
			ant->update(ticks, percept);
		}

		for (auto& antHill : world->getAntHills())
		{
			antHill->update(ticks);
		}

		auto& foodPiles = world->getAntFoodPiles();
		for (auto foodPile = foodPiles.begin(); foodPile != foodPiles.end(); ++foodPile)
		{
			if ((*foodPile)->getFoodCount() == 0)
			{
				foodPiles.erase(foodPile);
				break;
			}
		}

		if (antCountTimer.getElapsedTime().asSeconds() > 10.f)
		{
			cout << "Simulator: Ants: " << world->getAnts().size() << " | Live Ants: " << getLiveAntCount(*world) << endl;
			antCountTimer.restart();
		}
		
		clock.restart();
		++ticks;
	}
}

void Simulator::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (displayNavGraph)
	{
		for (auto& node : world->getNavGraph())
		{
			node.draw(target, states);
		}
	}

	if (displayAntPaths)
	{
		for (auto& ant : world->getAnts())
		{
			if (!ant->isDead())
			{
				ant->drawPath(target, states);
			}
		}
	}

	if (displayPheromones)
	{
		for (auto& node : world->getNavGraph())
		{
			for (auto& edge : node.getEdgeList())
			{
				edge->drawPheromone(target, states);
			}
		}
	}

	for (auto& antHill : world->getAntHills())
	{
		target.draw(*antHill);
	}

	// Draw dead ants.
	if (displayDeadAnts)
	{
		for (auto& ant : world->getAnts())
		{
			if (ant->isDead())
			{
				target.draw(*ant);
			}
		}
	}

	// Draw live ants.
	for (auto& ant : world->getAnts())
	{
		if (!ant->isDead())
		{
			target.draw(*ant);
		}
	}
	
	// Draw the selected ant again after all other ants have been drawn, to make
	// it easier to find the selected ant.
	auto selectedAnt = getSelectedAnt(world->getAnts());
	if (selectedAnt != nullptr)
	{
		target.draw(*selectedAnt);
	}

	for (auto& antFood : world->getAntFood())
	{
		target.draw(antFood);
	}

	for (auto& antFoodPile : world->getAntFoodPiles())
	{
		target.draw(*antFoodPile);
	}

	for (auto& sprite : world->getObstructions())
	{
		target.draw(sprite);
	}
}


// Starts a new simulation.
void Simulator::start(std::unique_ptr<World> world)
{
	this->world = std::move(world);
	this->world->create(eventManager);

	started = true;
	clock.restart();

	cout << "Simulator: started" << endl;
}

// Pauses the simulation.
void Simulator::pause()
{
	started = false;
	cout << "Simulator: paused" << endl;
}

void Simulator::unpause()
{
	started = true;
	clock.restart();

	cout << "Simulator: unpaused" << endl;
}

// Increases the speed of the simulation.
void Simulator::increaseSpeed()
{
	if ((speed + simSpeedIncrement) <= maxSimSpeed)
	{
		speed += simSpeedIncrement;
		cout << "Simulator: speed increased (" << speed << ")" << endl;
	}
	else
	{
		cout << "Simulator: at max speed" << endl;
	}
}

// Decreases the speed of the simulation.
void Simulator::decreaseSpeed()
{
	if ((speed - simSpeedIncrement) > minSimSpeed)
	{
		speed -= simSpeedIncrement;
		cout << "Simulator: speed decreased (" << speed << ")" << endl;
		if (speed == 0)
		{
			pause();
		}
	}
	else
	{
		cout << "Simulator: at min speed" << endl;
	}
}


bool Simulator::isPaused() const
{
	return !started;
}

void Simulator::drawPheromones()
{
	cout << (displayPheromones ? "Simulator: hide pheromones" : "Simulator: show pheromones") << endl;
	displayPheromones = !displayPheromones;
}

void Simulator::drawNavGraph()
{
	cout << (displayNavGraph ? "Simulator: hide nav graph" : "Simulator: show nav graph") << endl;
	displayNavGraph = !displayNavGraph;
}

void Simulator::drawDeadAnts()
{
	cout << (displayDeadAnts ? "Simulator: hide dead ants" : "Simulator: show dead ants") << endl;
	displayDeadAnts = !displayDeadAnts;
}

void Simulator::drawAntPaths()
{
	cout << (displayAntPaths ? "Simulator: hide ant paths" : "Simulator: show ants paths") << endl;
	displayAntPaths = !displayAntPaths;
}

uint getLiveAntCount(World& world)
{
	uint count = count_if(world.getAnts().cbegin(), world.getAnts().cend(), [](const unique_ptr<Ant>& ant) {
		return !ant->isDead();
	});
	return count;
}

const Ant* getSelectedAnt(const vector<unique_ptr<Ant>>& ants)
{
	auto selected = find_if(ants.cbegin(), ants.cend(), [](const unique_ptr<Ant>& ant) {
		return ant->isSelected();
	});

	if (selected != ants.end())
	{
		return selected->get();
	}
	return nullptr;
}