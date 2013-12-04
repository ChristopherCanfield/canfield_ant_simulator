#pragma once

// Christopher D. Canfield
// October 2013
// Simulator.hpp

#include "../util/Typedefs.hpp"
#include "world/World.hpp"

#include <SFML/System/Clock.hpp>

#include <boost/noncopyable.hpp>

#include <vector>
#include <memory>


namespace cdc 
{
	// The ant world simulator.
	class Simulator :
			public boost::noncopyable,
			public sf::Drawable
	{
	public:
		explicit Simulator(GuiEventManager& eventManager);
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

		// Returns true if the simulator is currently paused.
		bool isPaused() const;

		// Unhides the pheromones if they are currently hidden, or hides them 
		// if they are visible.
		void drawPheromones();

		// Unhides the nav graph if it is currently hidden, or hides it if it
		// is visible.
		void drawNavGraph();

		void Simulator::drawDeadAnts();

		// Performs one tick of the simulation.
		void update();

		static const uint defaultTicksPerSecond;

	protected:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		GuiEventManager& eventManager;
		
		bool started;
		uint speed;

		uint ticks;
		// Next tick time, in milliseconds.
		long nextTickTime;
		sf::Clock clock;

		bool displayPheromones;
		bool displayNavGraph;
		bool displayDeadAnts;

		std::unique_ptr<World> world;
	};
}

