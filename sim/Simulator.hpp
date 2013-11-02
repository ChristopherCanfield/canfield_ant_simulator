#pragma once

// Christopher D. Canfield
// October 2013
// Simulator.hpp

#include "../util/Typedefs.hpp"
#include "agent/Ant.hpp"
#include "agent/Spider.hpp"
#include "worldobject/AntFood.hpp"
#include "worldobject/AntFoodPile.hpp"
#include "world/World.hpp"

#include <boost/noncopyable.hpp>

#include <vector>
#include <memory>


namespace cdc 
{
	// The ant world simulator.
	class Simulator :
			public boost::noncopyable
	{
	public:
		Simulator(GuiEventManager& eventManager);
		~Simulator();

		// Starts a new simulation.
		void start(std::unique_ptr<World> world);

		// Pauses the simulation.
		void pause();

		// Unpauses the simulation.
		void unpause();

		// Increases the speed of the simulation.
		void increaseSpeed();

		// Decreases the speed of the simulation.
		void decreaseSpeed();

	private:
		GuiEventManager& eventManager;
		
		bool started;
		uint speed;

		std::unique_ptr<World> world;
	};
}

