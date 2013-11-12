#pragma once

#include "../Ant.hpp"

// Christopher D. Canfield
// November 2013
// AntGoHomeAntTest.hpp


namespace cdc
{
	// An ant used to test the AntGoHome goal.
	class AntGoHomeAntTest :
		public Ant
	{
	public:
		AntGoHomeAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper);
		virtual ~AntGoHomeAntTest();

		virtual void update(long ticks, const Percept& percept) override;

		friend class AntMoveToLocation;
		friend class AntGoHome;
	};
}
