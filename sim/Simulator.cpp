#include "Simulator.hpp"

#include <iostream>


// Christopher D. Canfield
// October 2013
// Simulator.hpp

using cdc::Simulator;

using namespace std;


uint max_sim_speed = 60;
uint min_sim_speed = 0;
uint sim_speed_increment = 10;


Simulator::Simulator() :
	started(false),
	speed(60)
{
}


Simulator::~Simulator()
{
}


// Starts a new simulation.
void Simulator::start()
{
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
