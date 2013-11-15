#pragma once

#include "AntGoalTester.hpp"

#include <deque>

// Christopher D. Canfield
// November 2013
// AntFollowPathAntTest.hpp


namespace cdc
{
	// An ant used for testing path following. Uses AntMoveToNode.
	class AntFollowPathAntTest :
		public AntGoalTester
	{
	public:
		AntFollowPathAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode, const Node& targetNode);
		virtual ~AntFollowPathAntTest();

		virtual void update(long ticks, const Percept& percept) override;

		virtual bool isGoalFinished() const override;

		friend class AntMoveToNode;
		friend class AntFollowPath;
	};
}