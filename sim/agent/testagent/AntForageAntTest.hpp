#pragma once

#include "AntGoalTester.hpp"

// Christopher D. Canfield
// November 2013
// AntForageAntTest.hpp


namespace cdc
{
	// An ant used to test the AntForage goal.
	class AntForageAntTest :
		public AntGoalTester
	{
	public:
		AntForageAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode);
		virtual ~AntForageAntTest();

		virtual void update(long ticks, const Percept& percept) override;

		virtual bool isGoalFinished() const override;

		friend class AntMoveToNode;
		friend class AntGoHome;
		friend class AntForage;
	};
}
