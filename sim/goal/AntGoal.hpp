#pragma once

#include "Goal.hpp"
#include "../agent/Ant.hpp"
#include "../knowledge/AntPercept.hpp"


namespace cdc
{

	class AntGoal :
			Goal<Ant, AntPercept>
	{
	public:
		AntGoal();
		virtual ~AntGoal();
		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;
	};
}
