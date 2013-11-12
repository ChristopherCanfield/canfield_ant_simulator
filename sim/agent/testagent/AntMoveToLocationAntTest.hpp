#pragma once

#include "AntGoalTester.hpp"

// Christopher D. Canfield
// November 2013
// AntMoveToLocationAntTest.hpp


namespace cdc
{
	// An ant used to test the AntMoveToLocation goal.
	class AntMoveToLocationAntTest :
		public AntGoalTester
	{
	public:
		AntMoveToLocationAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, Node& target);
		virtual ~AntMoveToLocationAntTest();

		virtual void update(long ticks, const Percept& percept) override;

		virtual bool isGoalFinished() const override;

		friend class AntMoveToLocation;
	};
}
