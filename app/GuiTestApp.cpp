#include "GuiTestApp.hpp"

#include <SFML/Window.hpp>
#include <SFML/System.hpp>


GuiTestApp::GuiTestApp()
{
}


GuiTestApp::~GuiTestApp()
{
}


void GuiTestApp::setup()
{
	window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(400, 400), "GUI Tests"));
	window->setFramerateLimit(60);

	// TODO: add gui elements for testing.
}


bool GuiTestApp::run()
{
	if (!window->isOpen())
	{
		return false;
	}

	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
			return false;
		}
		else
		{
			eventManager.update(event);
		}

	}

	window->clear();
	window->display();

	return true;
}


void GuiTestApp::teardown()
{
}
