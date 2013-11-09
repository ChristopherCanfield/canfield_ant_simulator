#pragma once

#include "Typedefs.hpp"

#include <random>


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

		int getInteger(int min, int max); 

	private:
		Random(const Random& other);
		Random(Random& other);

		static std::default_random_engine rand;
		static bool isSeeded;
	};
}