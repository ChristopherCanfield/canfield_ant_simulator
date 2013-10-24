#pragma once

#include "../knowledge/Percept.hpp"


namespace cdc
{
	// Interface for an intelligent agent.
	class Agent
	{
	public:
		// Called once per simulation tick.
		virtual void update(const Percept& percept) = 0;
	};
}