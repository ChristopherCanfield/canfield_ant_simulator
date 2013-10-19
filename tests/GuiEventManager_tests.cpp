#include "stdafx.h"
#include "CppUnitTest.h"

#include "../gui/GuiEventManager.hpp"

#include <SFML/Window/Event.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(GuiEventManager_tests)
	{
	public:

		// TODO (2013-10-16): More tests are needed.
		
		TEST_METHOD(GuiEventManager_create)
		{
			GuiEventManager manager;
		}

		TEST_METHOD(GuiEventManager_update_noValidEvent)
		{
			GuiEventManager manager;
			sf::Event event;
			manager.update(event);
		}

	};
}