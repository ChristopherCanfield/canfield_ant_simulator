#pragma once

#include "World.hpp"

// Christopher D. Canfield
// November 2013
// RandomWorld.hpp


namespace cdc
{
	// A world used for testing. It does not contain any functionality.
	class TestWorld :
		public World
	{
	public:
		TestWorld();
		virtual ~TestWorld();

		virtual void create(GuiEventManager& eventManager) override;
	};
}

