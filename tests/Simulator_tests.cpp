#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/Simulator.hpp"
#include "../sim/world/RandomWorld.hpp"
#include "../util/make_unique.hpp"

#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace cdc;

namespace tests
{
	TEST_CLASS(Simulator_tests)
	{
	public:
		
		TEST_METHOD(Simulator_create)
		{
			GuiEventManager manager;
			Simulator sim(manager);
		}

		TEST_METHOD(Simulator_start)
		{
			GuiEventManager manager;
			Simulator sim(manager);
			auto world = unique_ptr<World>(new RandomWorld());
			sim.start(move(world));
		}

		TEST_METHOD(Simulator_pause)
		{
			GuiEventManager manager;
			Simulator sim(manager);
			sim.pause();
		}

		TEST_METHOD(Simulator_unpause)
		{
			GuiEventManager manager;
			Simulator sim(manager);
			sim.unpause();
		}

		TEST_METHOD(Simulator_increaseSpeed)
		{
			GuiEventManager manager;
			Simulator sim(manager);
			sim.increaseSpeed();
		}

		TEST_METHOD(Simulator_decreaseSpeed)
		{
			GuiEventManager manager;
			Simulator sim(manager);
			sim.decreaseSpeed();
		}

		// Note that this does not succeed in Release mode, because the 
		// random seed generates a different set of numbers.
		TEST_METHOD(Simulator_getLiveAntCount)
		{
			Random rand;
			rand.setSeed(1);
			GuiEventManager manager;
			auto world = make_unique<RandomWorld>();

			Simulator sim(manager);
			sim.start(move(world));

			auto count = sim.getLiveAntCount();
			Assert::AreEqual(40u, count);
		}
	};
}