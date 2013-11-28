#pragma once

#include "World.hpp"
#include "../nav/NavGraphHelper.hpp"

// Christopher D. Canfield
// November 2013
// RandomWorld.hpp


namespace cdc
{
	class GuiEventManager;

	class RandomWorld :
			public World
	{
	public:
		RandomWorld();
		virtual ~RandomWorld();
		
		virtual void create(GuiEventManager& eventManager) override;

	private:
		RandomWorld(const RandomWorld&);
		RandomWorld& operator=(const RandomWorld& other);
	};
}
