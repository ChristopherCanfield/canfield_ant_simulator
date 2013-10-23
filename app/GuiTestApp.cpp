#include "GuiTestApp.hpp"

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


using cdc::GuiTestApp;


GuiTestApp::GuiTestApp() :
	decreaseSpeedButton(eventManager, simulator),
	increaseSpeedButton(eventManager, simulator),
	restartButton(eventManager, simulator),
	startButton(eventManager, simulator),
	stopButton(eventManager, simulator)
{
}


GuiTestApp::~GuiTestApp()
{
}


void GuiTestApp::setup()
{
	window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(400, 400), "GUI Tests"));
	window->setFramerateLimit(60);

	decreaseSpeedButton.setPosition(100, 100);
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

	window->clear(sf::Color::White);

	window->draw(decreaseSpeedButton);
	
	window->display();

	return true;
}


void GuiTestApp::teardown()
{
}
