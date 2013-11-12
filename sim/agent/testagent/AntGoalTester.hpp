#pragma once

#include "../Ant.hpp"


namespace cdc
{
	// Base class for AntGoal tester ants.
	class AntGoalTester :
		public Ant
	{
	public:
		AntGoalTester(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper) :
			Ant(manager, home, navGraphHelper) {}
		virtual ~AntGoalTester() {}
		virtual void update(long ticks, const Percept& percept) override {}
		virtual bool isGoalFinished() const = 0;
	};
}