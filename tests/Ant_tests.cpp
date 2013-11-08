#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/agent/Ant.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../sim/knowledge/GenericPercept.hpp"
#include "../sim/worldobject/AntHome.hpp"

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
			AntHome home;
			Ant ant(manager, home);
		}

		TEST_METHOD(Ant_update)
		{
			GuiEventManager manager;
			AntHome home;
			Ant ant(manager, home);

			GenericPercept percept;
			ant.update(10, percept);
		}
	};
}