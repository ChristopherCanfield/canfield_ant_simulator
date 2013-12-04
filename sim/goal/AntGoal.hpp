#pragma once

#include "Goal.hpp"
#include "../agent/Ant.hpp"
#include "../knowledge/AntPercept.hpp"

// Christopher D. Canfield
// November 2013
// AntGoal.hpp


namespace cdc
{
	// An ant agent's goal. Goals control the agent, and may contain subgoals.
	class AntGoal :
			Goal<Ant, AntPercept>
	{
	public:
		AntGoal(std::string goalName);
		virtual ~AntGoal();
		virtual void update(Ant& agent, uint ticks, AntPercept& percept) = 0;
		virtual void drawPath(sf::RenderTarget& target, sf::RenderStates states, const Node& lastNodePassed) const override;
		virtual bool isFinished() const override;

		virtual std::string toString() const override;

	protected:
		void setFinished(bool finished);

	private:
		bool finished;
		std::string goalName;
	};
}
