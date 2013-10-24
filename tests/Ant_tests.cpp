#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/agent/Ant.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../sim/knowledge/GenericPercept.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(Ant_tests)
	{
	public:
		
		TEST_METHOD(Ant_create)
		{
			GuiEventManager manager;
			Ant ant(manager);
		}

		TEST_METHOD(Ant_update)
		{
			GuiEventManager manager;
			Ant ant(manager);

			GenericPercept percept;
			ant.update(percept);
		}
	};
}