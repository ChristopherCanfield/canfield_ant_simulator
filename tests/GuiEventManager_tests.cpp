#include "stdafx.h"
#include "CppUnitTest.h"

#include "../gui/GuiEventManager.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(GuiEventManager_tests)
	{
	public:

		TEST_METHOD(GuiEventManager_create)
		{
			GuiEventManager manager;
		}

		TEST_METHOD(GuiEventManager_update_noValidEvent)
		{
			sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
			GuiEventManager manager;
			sf::Event event;
			manager.update(event, window);
		}

	};
}