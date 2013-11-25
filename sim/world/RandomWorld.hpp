#pragma once

#include "World.hpp"

// Christopher D. Canfield
// November 2013
// RandomWorld.hpp


namespace cdc
{
	class RandomWorld :
			public World
	{
	public:
		RandomWorld();
		virtual ~RandomWorld();
		
		virtual void create(GuiEventManager& eventManager) override;
	};
}
