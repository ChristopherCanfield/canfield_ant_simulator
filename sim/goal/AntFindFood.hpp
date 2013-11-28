#pragma once

#include "AntGoal.hpp"

// Christopher D. Canfield
// November 2013
// AntFindFood.hpp


namespace cdc 
{
	// A subgoal that instructs the ant to find food. Once the food
	// has been found, isFinished() returns true. Other goals or subgoals are then
	// used to actually determine what to do with the food (eat / pick up)
	class AntFindFood :
			public AntGoal
	{
	public:
		AntFindFood();
		virtual ~AntFindFood();

		virtual void update(Ant& agent, uint ticks, AntPercept& percept) override;

		virtual void drawPath(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		void setGoal(Ant& ant);

		std::unique_ptr<AntGoal> goal;

		bool foodFound;
	};
}

