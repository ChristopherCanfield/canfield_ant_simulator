#pragma once

#include "AntGoalTester.hpp"

// Christopher D. Canfield
// November 2013
// AntEatTestAnt.hpp


namespace cdc
{
	// An ant used for testing the AntEat goal.
	class AntEatTestAnt :
		public AntGoalTester
	{
	public:
		AntEatTestAnt(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper);
		virtual ~AntEatTestAnt();

		virtual void update(long ticks, const Percept& percept) override;

		virtual bool isGoalFinished() const override;

		friend class AntEat;
		friend class AntMoveToLocation;
	};
}
