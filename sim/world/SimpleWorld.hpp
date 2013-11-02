#pragma once

#include "World.hpp"

// Christopher D. Canfield
// November 2013
// SimpleWorld.hpp


namespace cdc
{
	class SimpleWorld :
			public World
	{
	public:
		SimpleWorld();
		virtual ~SimpleWorld();
		
		virtual void create(GuiEventManager& eventManager) override;
	};
}
