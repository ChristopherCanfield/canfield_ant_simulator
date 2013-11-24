#include "AiSimApp.hpp"

#include <SFML/Window.hpp>

#include <iostream>

// Christopher D. Canfield
// October 2013
// AiSimApp.cpp

using namespace cdc;
using namespace std;
using namespace sf;

AiSimApp::AiSimApp() :
	simulator(eventManager)
{
}


AiSimApp::~AiSimApp()
{
}


void AiSimApp::setup()
{

}

bool AiSimApp::run()
{
	return false;
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

void processInput(const sf::Event& e, Simulator& sim)
{
	if (e.type == Event::KeyReleased)
	{
		if (e.key.code == Keyboard::Subtract)
		{
			// TODO: decrease sim speed.
		}
		else if (e.key.code == Keyboard::Add || e.key.code == Keyboard::Equal)
		{
			// TODO: increase sim speed.
		}
		else if (e.key.code == Keyboard::Num1)
		{
			// TODO: draw nav graph.
		}
		else if (e.key.code == Keyboard::Num2)
		{
			// TODO: draw pheromones.
		}
		else if (e.key.code == Keyboard::Escape)
		{
			// TODO: close window.
		}
	}
}