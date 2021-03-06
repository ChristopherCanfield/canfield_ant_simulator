#pragma once

#include "AntGoalTester.hpp"

// Christopher D. Canfield
// November 2013
// AntMoveToNodeAntTest.hpp


namespace cdc
{
	// An ant used to test the AntMoveToNode goal.
	class AntMoveToNodeAntTest :
		public AntGoalTester
	{
	public:
		AntMoveToNodeAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode, Node& target);
		virtual ~AntMoveToNodeAntTest();

		virtual void update(uint ticks, const Percept& percept) override;

		virtual bool isGoalFinished() const override;

		friend class AntMoveToNode;
	};
}
