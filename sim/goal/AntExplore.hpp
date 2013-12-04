#pragma once

#include "AntGoal.hpp"

#include <deque>
#include <memory>

// Christopher D. Canfield
// November 2013
// AntExplore.hpp


namespace cdc 
{
	// A top-level goal that instructs the ant to explore the map. The ant does
	// not look for anything specific, but does take note of food it finds.
	class AntExplore :
			public AntGoal
	{
	public:
		AntExplore(bool debug = false);
		virtual ~AntExplore();

		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;

		virtual void drawPath(sf::RenderTarget& target, sf::RenderStates states, const Node& lastNodePassed) const override;

		virtual std::string toString() const override;

	private:
		std::deque<Node*> path;
		std::unique_ptr<AntGoal> subgoal;

		Node& getNewTarget(const Ant& ant);
		void processNextInPath(Ant& ant);

		bool debug;
	};
}

