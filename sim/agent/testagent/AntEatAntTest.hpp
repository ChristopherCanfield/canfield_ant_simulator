#pragma once

#include "AntGoalTester.hpp"

// Christopher D. Canfield
// November 2013
// AntEatAntTest.hpp


namespace cdc
{
	// An ant used for testing the AntEat goal.
	class AntEatAntTest :
		public AntGoalTester
	{
	public:
		AntEatAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode);
		virtual ~AntEatAntTest();

		virtual void update(uint ticks, const Percept& percept) override;

		virtual bool isGoalFinished() const override;

		friend class AntEat;
		friend class AntMoveToNode;
	};
}
