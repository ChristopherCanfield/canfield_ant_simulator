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


// Starts the simulation.
void Simulator::start()
{
	started = true;
	cout << "Simulator: started" << endl;
	// TODO: start the simulation.
}

// Stops the simulation.
void Simulator::stop()
{
	started = false;
	cout << "Simulator: stopped" << endl;
	// TODO: stop the simulation.
}

void Simulator::restart()
{
	started = true;
	cout << "Simulator: restarted" << endl;
	// TODO: reset the simulation, and then start it.
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
			stop();
		}
	}
	else
	{
		cout << "Simulator: at min speed" << endl;
	}
}
