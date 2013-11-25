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
		AntGoHomeAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode);
		virtual ~AntGoHomeAntTest();

		virtual void update(uint ticks, const Percept& percept) override;

		virtual bool isGoalFinished() const override;

		friend class AntMoveToNode;
		friend class AntGoHome;
	};
}
