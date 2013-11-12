#pragma once

#include "../Ant.hpp"

// Christopher D. Canfield
// November 2013
// AntExploreAntTest.hpp


namespace cdc
{
	// An ant used to test the AntExplore goal.
	class AntExploreAntTest :
		public Ant
	{
	public:
		AntExploreAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper);
		virtual ~AntExploreAntTest();

		virtual void update(long ticks, const Percept& percept) override;

		friend class AntMoveToLocation;
		friend class AntExplore;
	};
}
