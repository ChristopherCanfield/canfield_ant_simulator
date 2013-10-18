#pragma once

// Christopher D. Canfield
// October 2013
// Simulator.hpp

#include "../lib/boost/noncopyable.hpp"


class Simulator :
		public boost::noncopyable
{
public:
	Simulator();
	~Simulator();

	// Starts the simulation.
	void start();

	// Stops the simulation.
	void stop();

	// Increases the speed of the simulation.
	void increaseSpeed();

	// Decreases the speed of the simulation.
	void decreaseSpeed();

private:
	bool started;


};

