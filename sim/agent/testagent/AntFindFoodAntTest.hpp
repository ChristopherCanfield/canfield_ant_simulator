#pragma once

#include "AntGoalTester.hpp"

// Christopher D. Canfield
// November 2013
// AntFindFoodAntTest.hpp


namespace cdc
{
	// An ant used to explore the AntFindFood goal.
	class AntFindFoodAntTest :
		public AntGoalTester
	{
	public:
		AntFindFoodAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode);
		virtual ~AntFindFoodAntTest();

		virtual void update(uint ticks, const Percept& percept) override;

		virtual bool isGoalFinished() const override;

		friend class AntMoveToNode;
		friend class AntGoHome;
		friend class AntFindFood;
	};
}
