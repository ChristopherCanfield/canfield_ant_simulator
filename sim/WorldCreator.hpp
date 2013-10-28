#pragma once

// Christopher D. Canfield
// October 2013
// WorldCreator.hpp


namespace cdc
{
	// Interface for world creators. World creators define the simulation world,
	// including the nav graph and initial locations of entities in the world.
	class WorldCreator
	{
		// Creates the world.
		virtual void create() = 0;
	};
}