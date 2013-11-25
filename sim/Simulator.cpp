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


uint max_sim_speed = 60;
uint min_sim_speed = 0;
uint sim_speed_increment = 10;
uint default_sim_speed = 30;


Simulator::Simulator(GuiEventManager& eventManager) :
	eventManager(eventManager),
	started(false),
	speed(default_sim_speed),
	displayPheromones(false),
	displayNavGraph(false)
{
}


Simulator::~Simulator()
{
}


void Simulator::update()
{
	if (started)
	{
		for (auto& node : world->getNavGraph())
		{
			node.update(ticks);
		}

		GenericPercept percept;
		for (auto& ant : world->getAnts())
		{
			ant.update(ticks, percept);
		}

		for (auto& antHill : world->getAntHills())
		{
			antHill.update(ticks);
		}
		
		++ticks;
	}
}

void Simulator::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
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

	if (displayNavGraph)
	{
		for (auto& node : world->getNavGraph())
		{
			node.draw(target, states);
		}
	}

	for (auto& ant : world->getAnts())
	{
		target.draw(ant);
	}

	for (auto& antFood : world->getAntFood())
	{
		target.draw(antFood);
	}

	for (auto& antFoodPile : world->getAntFoodPiles())
	{
		target.draw(antFoodPile);
	}

	for (auto& antHill : world->getAntHills())
	{
		target.draw(antHill);
	}
}


// Starts a new simulation.
void Simulator::start(std::unique_ptr<World> world)
{
	this->world = std::move(world);
	this->world->create(eventManager);

	started = true;
	cout << "Simulator: started" << endl;

	// TODO: start a new simulation.
}

// Pauses the simulation.
void Simulator::pause()
{
	started = false;
	cout << "Simulator: paused" << endl;
	// TODO: pause the simulation.
}

void Simulator::unpause()
{
	started = true;
	cout << "Simulator: unpaused" << endl;
	// TODO: unpause the simulation.
}

// Increases the speed of the simulation.
void Simulator::increaseSpeed()
{
	if ((speed + sim_speed_increment) <= max_sim_speed)
	{
		speed += sim_speed_increment;
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
	if ((speed - sim_speed_increment) > min_sim_speed)
	{
		speed -= sim_speed_increment;
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