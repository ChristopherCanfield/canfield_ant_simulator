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

		// Starts a new simulation.
		void start();

		// Pauses the simulation.
		void pause();

		// Unpauses the simulation.
		void unpause();

		// Increases the speed of the simulation.
		void increaseSpeed();

		// Decreases the speed of the simulation.
		void decreaseSpeed();

	private:
		bool started;
		uint speed;
	};
}

