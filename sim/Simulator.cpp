#include "Simulator.hpp"


// Christopher D. Canfield
// October 2013
// Simulator.hpp

using cdc::Simulator;


uint max_sim_speed = 60;
uint min_sim_speed = 0;
uint sim_speed_increment = 10;


Simulator::Simulator()
{
}


Simulator::~Simulator()
{
}


// Starts the simulation.
void Simulator::start()
{
	started = true;
	// TODO: start the simulation.
}

// Stops the simulation.
void Simulator::stop()
{
	started = false;
	// TODO: stop the simulation.
}

void Simulator::restart()
{
	started = true;
	// TODO: reset the simulation, and then start it.
}

// Increases the speed of the simulation.
void Simulator::increaseSpeed()
{
	if ((speed + sim_speed_increment) <= max_sim_speed)
	{
		speed += sim_speed_increment;
	}
}

// Decreases the speed of the simulation.
void Simulator::decreaseSpeed()
{
	if ((speed - sim_speed_increment) > min_sim_speed)
	{
		speed -= sim_speed_increment;
		if (speed == 0)
		{
			stop();
		}
	}
}
