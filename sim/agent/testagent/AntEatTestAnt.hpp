#pragma once

#include "../Ant.hpp"


// Christopher D. Canfield
// November 2013
// AntEatTestAnt.hpp


namespace cdc
{
	// An ant used for testing the AntEat goal.
	class AntEatTestAnt :
		public Ant
	{
	public:
		AntEatTestAnt(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper);
		virtual ~AntEatTestAnt();

		virtual void update(long ticks, const Percept& percept) override;

		friend class AntEat;
		friend class AntMoveToLocation;
	};
}
