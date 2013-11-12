#pragma once

#include "../Ant.hpp"

// Christopher D. Canfield
// November 2013
// AntMoveToLocationAntTest.hpp


namespace cdc
{
	// An ant used to test the AntMoveToLocation goal.
	class AntMoveToLocationAntTest :
		public Ant
	{
	public:
		AntMoveToLocationAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper);
		virtual ~AntMoveToLocationAntTest();

		virtual void update(long ticks, const Percept& percept) override;

		friend class AntMoveToLocation;
	};
}
