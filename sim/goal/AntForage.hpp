#pragma once

#include "AntGoal.hpp"
#include "AntFindFood.hpp"
#include "AntGoHome.hpp"

// Christopher D. Canfield
// November 2013
// AntForage.hpp


namespace cdc 
{
	// A goal that instructs the ant to forage for food.
	class AntForage :
			public AntGoal
	{
	public:
		AntForage();
		virtual ~AntForage();

		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;

	private:
		AntFindFood antFindFoodSubgoal;
		AntGoHome antGoHomeSubgoal;
		AntGoal* currentSubgoal;
	};
}

