#pragma once

#include "AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntMoveToLocation.hpp


namespace cdc 
{
	class Node;

	// A subgoal that instructs the ant to return home.
	class AntMoveToLocation :
			public AntGoal
	{
	public:
		AntMoveToLocation(Ant& ant, Node& target);
		virtual ~AntMoveToLocation();

		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;
		void reset(Ant& ant, Node& newTarget);

	private:
		AntMoveToLocation(const AntMoveToLocation&);
		AntMoveToLocation& operator=(const AntMoveToLocation&);

		Node* target;

		// Calculates the ant's movement vectors, and rotates it to face the 
		// new target.
		void calculateMovementVectors(Ant& ant);
	};
}