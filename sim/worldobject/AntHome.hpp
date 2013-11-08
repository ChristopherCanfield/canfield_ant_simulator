#pragma once

#include "../util/Typedefs.hpp"


// Christopher D. Canfield
// November 2013
// AntHome.hpp


namespace cdc
{
	// The home for a colony of Ants. Stores food and generates new ants.
	class AntHome
	{
	public:
		AntHome();
		~AntHome();

		// Returns a count of the food stored in the anthill.
		uint getFoodCount() const;

		// Takes one food. Returns true if successful, or false if not 
		// (i.e., there wasn't enough food).
		bool takeFood();

		// Adds one food to the anthill store.
		void addFood();

	private:
		uint foodCount;
	};
}
