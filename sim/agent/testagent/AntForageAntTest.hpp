#pragma once

#include "../Ant.hpp"

// Christopher D. Canfield
// November 2013
// AntForageAntTest.hpp


namespace cdc
{
	// An ant used to test the AntForage goal.
	class AntForageAntTest :
		public Ant
	{
	public:
		AntForageAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper);
		virtual ~AntForageAntTest();

		virtual void update(long ticks, const Percept& percept) override;

		friend class AntMoveToLocation;
		friend class AntGoHome;
		friend class AntForage;
	};
}
