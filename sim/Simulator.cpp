#include "Simulator.hpp"
#include "world/World.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../sim/knowledge/GenericPercept.hpp"

#include <iostream>


// Christopher D. Canfield
// October 2013
// Simulator.hpp

using cdc::Simulator;
using cdc::World;
using cdc::GuiEventManager;

using namespace std;


uint maxSimSpeed = 90;
uint minSimSpeed = 0;
uint simSpeedIncrement = 10;

const uint Simulator::defaultTicksPerSecond = 60;


Simulator::Simulator(GuiEventManager& eventManager) :
	eventManager(eventManager),
	started(false),
	speed(defaultTicksPerSecond),
	displayPheromones(false),
	displayNavGraph(false),
	displayDeadAnts(true),
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

	for (auto& ant : world->getAnts())
	{
		if (displayDeadAnts || !ant->isDead())
		{
			target.draw(*ant);
		}
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

	for (auto& antHill : world->getAntHills())
	{
		target.draw(*antHill);
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
		cout << "Simulator: speed increased" << endl;
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
		cout << "Simulator: speed decreased" << endl;
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
	displayPheromones = !displayPheromones;
}

void Simulator::drawNavGraph()
{
	displayNavGraph = !displayNavGraph;
}

void Simulator::drawDeadAnts()
{
	displayDeadAnts = !displayDeadAnts;
}