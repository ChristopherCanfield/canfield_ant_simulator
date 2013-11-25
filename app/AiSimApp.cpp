#include "AiSimApp.hpp"

#include <SFML/Window.hpp>

#include <iostream>

// Christopher D. Canfield
// October 2013
// AiSimApp.cpp

using namespace cdc;
using namespace std;
using namespace sf;

bool processInput(const sf::Event& e, sf::Window& window, Simulator& sim);
int getSeed();


AiSimApp::AiSimApp() :
	simulator(eventManager)
{
}


AiSimApp::~AiSimApp()
{
}


void AiSimApp::setup()
{
	Random::setSeed(getSeed());
}

bool AiSimApp::run()
{
	bool continueRunning = true;
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			return false;
		}
		else
		{
			continueRunning = processInput(event, window, simulator);
			eventManager.update(event, window);
		}
	}

	simulator.update();
	window.draw(simulator);
	
	return continueRunning;
}

void AiSimApp::teardown()
{
}



// Gets the seed for the random number generator from the player.
int getSeed()
{
	cout << "Seed: ";
	int seed = 0;
	cin >> seed;
	return seed;
}

bool processInput(const sf::Event& e, sf::Window& window, Simulator& sim)
{
	if (e.type == Event::KeyReleased)
	{
		if (e.key.code == Keyboard::Subtract)
		{
			sim.decreaseSpeed();
		}
		else if (e.key.code == Keyboard::Add || e.key.code == Keyboard::Equal)
		{
			sim.increaseSpeed();
		}
		else if (e.key.code == Keyboard::Num1)
		{
			sim.drawNavGraph();
		}
		else if (e.key.code == Keyboard::Num2)
		{
			sim.drawPheromones();
		}
		else if (e.key.code == Keyboard::Escape)
		{
			window.close();
			return false;
		}
	}
	return true;
}