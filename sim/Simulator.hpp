#pragma once

// Christopher D. Canfield
// October 2013
// Simulator.hpp

#include "../util/Typedefs.hpp"

#include <boost/noncopyable.hpp>

namespace cdc 
{
	class Simulator :
			public boost::noncopyable
	{
	public:
		Simulator();
		~Simulator();

		// Starts (unpauses) the simulation.
		void start();

		// Stops (pauses) the simulation.
		void stop();

		// Restarts (resets) the simulation.
		void restart();

		// Increases the speed of the simulation.
		void increaseSpeed();

		// Decreases the speed of the simulation.
		void decreaseSpeed();

	private:
		bool started;
		uint speed;
	};
}

