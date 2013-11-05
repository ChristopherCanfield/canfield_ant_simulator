#pragma once

#include "../util/Typedefs.hpp"


// Christopher D. Canfield
// November 2013
// Goal.hpp


namespace cdc 
{
	// An agent's goal.
	template<class AgentType, class PerceptType>
	class Goal
	{
	public:
		virtual ~Goal() {}
		virtual void update(AgentType& agent, uint ticks, PerceptType& percept) = 0;
	};
}
