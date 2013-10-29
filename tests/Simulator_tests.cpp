#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/Simulator.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(Simulator_tests)
	{
	public:
		
		TEST_METHOD(Simulator_create)
		{
			Simulator sim;
		}

		TEST_METHOD(Simulator_start)
		{
			Simulator sim;
			sim.start();
		}

		TEST_METHOD(Simulator_pause)
		{
			Simulator sim;
			sim.pause();
		}

		TEST_METHOD(Simulator_unpause)
		{
			Simulator sim;
			sim.unpause();
		}

		TEST_METHOD(Simulator_increaseSpeed)
		{
			Simulator sim;
			sim.increaseSpeed();
		}

		TEST_METHOD(Simulator_decreaseSpeed)
		{
			Simulator sim;
			sim.decreaseSpeed();
		}

	};
}