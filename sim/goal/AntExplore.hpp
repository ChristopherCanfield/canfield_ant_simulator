#pragma once

#include "AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntExplore.hpp


namespace cdc 
{
	// A top-level goal that instructs the ant to explore the map.
	class AntExplore :
			public AntGoal
	{
	public:
		AntExplore();
		virtual ~AntExplore();

		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;
	};
}

