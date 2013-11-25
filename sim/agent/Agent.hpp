#pragma once

// Christopher D. Canfield
// October 2013
// Agent.hpp

#include "../knowledge/Percept.hpp"


namespace cdc
{
	// Interface for an intelligent agent.
	class Agent
	{
	public:
		virtual ~Agent() {}

		// Called once per simulation tick.
		virtual void update(uint ticks, const Percept& percept) = 0;
	};
}