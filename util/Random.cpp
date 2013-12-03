#include "Random.hpp"

#include <random>

// Christopher D. Canfield
// November 2013
// Random.cpp

// Adapted from Bjarne Stroustrup: http://www.stroustrup.com/C++11FAQ.html#std-random
// as well as cplusplus.com: http://www.cplusplus.com/reference/random/


using cdc::Random;
using namespace std;


std::default_random_engine cdc::Random::rand;
bool cdc::Random::isSeeded;



Random::Random(uint seed)
{
	if (!isSeeded)
	{
		rand.seed(seed);
		isSeeded = true;
	}
}

Random::Random()
{
}

void Random::setSeed(uint seed)
{
	rand.seed(seed);
	isSeeded = true;
}

int Random::getInteger(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(rand);
}