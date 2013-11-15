#pragma once

#include "AntGoal.hpp"

#include <memory>
#include <deque>

// Christopher D. Canfield
// November 2013
// AntFollowPath.hpp


namespace cdc 
{
	class AntFollowPath :
		public AntGoal
	{
	public:
		AntFollowPath(Ant& ant, const Node& target, bool debug = false);
		virtual ~AntFollowPath();

		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;

	private:
		std::deque<Node*> path;
		std::unique_ptr<AntMoveToNode> subgoal;

		bool debug;
	};
}

