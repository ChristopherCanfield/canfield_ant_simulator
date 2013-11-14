#pragma once

#include "AntGoalTester.hpp"

// Christopher D. Canfield
// November 2013
// AntGoHomeAntTest.hpp


namespace cdc
{
	// An ant used to test the AntGoHome goal.
	class AntGoHomeAntTest :
		public AntGoalTester
	{
	public:
		AntGoHomeAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper);
		virtual ~AntGoHomeAntTest();

		virtual void update(long ticks, const Percept& percept) override;

		virtual bool isGoalFinished() const override;

		friend class AntMoveToNode;
		friend class AntGoHome;
	};
}
