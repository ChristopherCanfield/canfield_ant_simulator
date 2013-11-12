#pragma once

#include "AntGoal.hpp"

#include <deque>
#include <memory>


// Christopher D. Canfield
// November 2013
// AntGoHome.hpp


namespace cdc 
{
	class Node;

	// A subgoal that instructs the ant to return home.
	class AntGoHome :
			public AntGoal
	{
	public:
		AntGoHome();
		virtual ~AntGoHome();

		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;

	private:
		// The path to the ant's home.
		std::deque<Node*> path;

		Node* currentTarget;

		std::unique_ptr<AntGoal> subgoal;
	};
}

