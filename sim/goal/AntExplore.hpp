#pragma once

#include "AntGoal.hpp"

#include <deque>

// Christopher D. Canfield
// November 2013
// AntExplore.hpp


namespace cdc 
{
	// A top-level goal that instructs the ant to explore the map. The ant does
	// not look for anything specific, but does take note of food it finds.
	class AntExplore :
			public AntGoal
	{
	public:
		AntExplore();
		virtual ~AntExplore();

		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;

	private:
		std::deque<Node*> path;
	};
}

