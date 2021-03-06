#pragma once

#include "Typedefs.hpp"

#include <random>

// Christopher D. Canfield
// November 2013
// Random.hpp


namespace cdc
{
	// Simplifies the use of the random number generator. The seed is only set
	// once. Once the Random(seed) constructor is used, subsequent usages of it 
	// are ignored.
	class Random
	{
	public:
		explicit Random(uint seed);
		Random();

		static void setSeed(uint seed);

		// Returns a random integer, between min and max, inclusive.
		int getInteger(int min, int max);

	private:
		Random(const Random& other);

		static std::default_random_engine rand;
		static bool isSeeded;
	};
}