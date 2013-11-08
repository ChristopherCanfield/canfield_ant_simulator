#pragma once

#include "Goal.hpp"
#include "../agent/Ant.hpp"
#include "../knowledge/AntPercept.hpp"

// Christopher D. Canfield
// November 2013
// AntGoal.hpp


namespace cdc
{

	class AntGoal :
			Goal<Ant, AntPercept>
	{
	public:
		AntGoal();
		virtual ~AntGoal();
		virtual void update(Ant& agent, uint ticks, AntPercept& percept) = 0;
		virtual bool isFinished() const override;

	protected:
		void setFinished(bool finished);

	private:
		bool finished;
	};
}
