#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/Simulator.hpp"
#include "../sim/world/SimpleWorld.hpp"

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
			auto world = unique_ptr<World>(new SimpleWorld());
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

	};
}