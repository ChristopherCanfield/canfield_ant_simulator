#pragma once

#include "AntGoalTester.hpp"

// Christopher D. Canfield
// November 2013
// AntExploreAntTest.hpp


namespace cdc
{
	// An ant used to test the AntExplore goal.
	class AntExploreAntTest :
		public AntGoalTester
	{
	public:
		AntExploreAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode);
		virtual ~AntExploreAntTest();

		virtual void update(uint ticks, const Percept& percept) override;

		virtual bool isGoalFinished() const override;

		friend class AntMoveToNode;
		friend class AntExplore;
	};
}
