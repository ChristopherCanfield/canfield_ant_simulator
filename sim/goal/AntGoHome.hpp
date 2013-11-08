#pragma once

#include "AntGoal.hpp"


// Christopher D. Canfield
// November 2013
// AntGoHome.hpp


namespace cdc 
{
	// A subgoal that instructs the ant to return home.
	class AntGoHome :
			public AntGoal
	{
	public:
		AntGoHome();
		virtual ~AntGoHome();

		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;
	};
}

