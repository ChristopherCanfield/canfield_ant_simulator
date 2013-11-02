#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/agent/Spider.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../sim/knowledge/GenericPercept.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(Spider_tests)
	{
	public:
		
		TEST_METHOD(Spider_create)
		{
			GuiEventManager manager;
			Spider spider(manager);
		}

		TEST_METHOD(Ant_update)
		{
			GuiEventManager manager;
			Spider spider(manager);

			GenericPercept percept;
			spider.update(20, percept);
		}
	};
}