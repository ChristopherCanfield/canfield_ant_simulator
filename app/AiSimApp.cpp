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
void printUserCommands();


AiSimApp::AiSimApp() :
	simulator(eventManager),
	// TODO: the world size should come from the simulator.
	viewManager(eventManager, 3000, 3000, 800, 800, 200, 800)
{
	backgroundImage.loadFromFile("res/grass1 - stylized.jpg");
	backgroundImage.setRepeated(true);

	// TODO: the world size should come from the simulator.
	background.setTextureRect(sf::IntRect(0, 0, 3000, 3000));
	background.scale(.75f, .75f);
	background.setTexture(&backgroundImage);
}


AiSimApp::~AiSimApp()
{
}


void AiSimApp::setup()
{
	Random::setSeed(getSeed());

	cout << endl;
	printUserCommands();
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

	window.clear(sf::Color::White);

	window.setView(viewManager.getSimView());

	window.draw(background);
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

void printUserCommands()
{
	cout << "Simulation Commands" << endl
		<<  "-------------------" << endl
		<< "  Space:  Pause/Unpause" << endl
		<< "  +:      Increase simulation speed" << endl
		<< "  -:      Decrease simulation speed" << endl
		<< "  1:      Show/Hide navigation graph" << endl
		<< "  2:      Show/Hide pheromone strength" << endl
		<< "  Escape: Exit" << endl;
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
		else if (e.key.code == Keyboard::Space)
		{
			if (sim.isPaused())
			{
				sim.unpause();
			}
			else
			{
				sim.pause();
			}
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