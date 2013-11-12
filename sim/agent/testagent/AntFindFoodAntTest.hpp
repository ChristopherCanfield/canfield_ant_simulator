#pragma once

#include "../Ant.hpp"

// Christopher D. Canfield
// November 2013
// AntFindFoodAntTest.hpp


namespace cdc
{
	// An ant used to explore the AntFindFood goal.
	class AntFindFoodAntTest :
		public Ant
	{
	public:
		AntFindFoodAntTest(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper);
		virtual ~AntFindFoodAntTest();

		virtual void update(long ticks, const Percept& percept) override;

		friend class AntMoveToLocation;
		friend class AntGoHome;
		friend class AntFindFood;
	};
}
