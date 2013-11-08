#pragma once

#include "AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntFindFood.hpp


namespace cdc 
{
	// A subgoal that instructs the ant to find food.
	class AntFindFood :
			public AntGoal
	{
	public:
		AntFindFood();
		virtual ~AntFindFood();

		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;
	};
}

