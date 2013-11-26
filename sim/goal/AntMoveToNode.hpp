#pragma once

#include "AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntMoveToNode.hpp


namespace cdc 
{
	class Node;

	// A subgoal that instructs the ant to move to the specified node. This goal
	// does not create a path from the current node to the target node. Instead,
	// it moves the ant directly to the target. For that reason, it should be used
	// as a subgoal within a larger goal that uses paths.
	class AntMoveToNode :
			public AntGoal
	{
	public:
		AntMoveToNode(Ant& ant, const Node& target, bool debug = false);
		virtual ~AntMoveToNode();

		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;
		void reset(Ant& ant, Node& newTarget);

	private:
		AntMoveToNode(const AntMoveToNode&);
		AntMoveToNode& operator=(const AntMoveToNode&);

		bool debug;
		const Node* target;

		// Calculates the ant's movement vectors, and rotates it to face the 
		// new target.
		void calculateMovementVectors(Ant& ant);
	};
}