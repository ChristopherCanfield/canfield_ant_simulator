#pragma once

#include "AntGoal.hpp"
#include "AntGoHome.hpp"
#include "AntFindFood.hpp"

// Christopher D. Canfield
// November 2013
// AntEat.hpp


namespace cdc 
{
	// A top-level goal that instructs the ant to find food, and eat it once 
	// food has been found.
	class AntEat :
			public AntGoal
	{
	public:
		AntEat();
		virtual ~AntEat();

		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;

	private:
		AntGoHome antGoHomeSubgoal;
		AntFindFood antFindFoodSubgoal;
		AntGoal* currentSubgoal;
	};
}

