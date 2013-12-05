#include "AiSimApp.hpp"
#include "../sim/world/RandomWorld.hpp"
#include "../util/Random.hpp"
#include "../util/make_unique.hpp"

#include <SFML/Window.hpp>

#include <iostream>

// Christopher D. Canfield
// October 2013
// AiSimApp.cpp

using namespace cdc;
using namespace std;
using namespace sf;

int getSeed();
void printUserCommands();
void printWorldStats(World& world);


AiSimApp::AiSimApp() :
	simulator(eventManager),
	// TODO: the world size should come from the simulator.
	viewManager(eventManager, 3100, 3100, 800, 800, 200, 800),
	background(sf::Vector2f(3100, 3100)),
	drawBackground(true)
{
	backgroundImage.loadFromFile("res/grass1 - stylized.jpg");
	backgroundImage.setRepeated(true);

	// TODO: the world size should come from the simulator.
	background.setTextureRect(sf::IntRect(0, 0, 3100, 3100));
	background.setTexture(&backgroundImage);
}


AiSimApp::~AiSimApp()
{
}


void AiSimApp::setup()
{
	Random::setSeed(getSeed());

	unique_ptr<World> world = make_unique<RandomWorld>();
	printWorldStats(*world.get());

	cout << endl;
	printUserCommands();

	window.create(sf::VideoMode(800, 800), "Canfield: Ant Simulator");
	// Limiting the frame rate reduces CPU usage by ~75% on my desktop.
	window.setFramerateLimit(130);

	viewManager.setWindow(window);
	viewManager.getSimView().setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	viewManager.setViewParameters(1150.f, 1150.f, 3.9f);

	simulator.start(move(world));
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

	window.clear(sf::Color(211, 211, 211));
	
	window.setView(viewManager.getSimView());
	if (drawBackground)
	{
		window.draw(background);
	}
	window.draw(simulator);

	window.display();
	
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

void printWorldStats(World& world)
{
	if (!world.getAntHills().empty())
	{
		auto antHillNode = world.getAntHills()[0]->getNode();
		cout << endl 
			<< "Ant hill location: (" << antHillNode.getRow() << "," << antHillNode.getColumn() << ")" << endl
			<< "Number of food piles: " << world.getAntFoodPiles().size() << endl
			<< "Number of ants: " << world.getAnts().size() << endl;
	}
}

void printUserCommands()
{
	cout << endl << "Simulation Commands" << endl
		<<  "-------------------" << endl
		<< "  Space.........Pause/Unpause" << endl
		<< "  +.............Increase simulation speed" << endl
		<< "  -.............Decrease simulation speed" << endl
		<< "  1.............Show/Hide navigation graph" << endl
		<< "  2.............Show/Hide pheromone strength" << endl
		<< "  3.............Show/hide ant paths" << endl
		<< "  4.............Show/Hide dead ants" << endl
		<< "  5.............Show/Hide background" << endl
		<< "  Mouse Wheel...Zoom in/out" << endl
		<< "  Arrow Keys....Move screen up/down/left/right" << endl 
		<< "  ?.............Redisplay these commands" << endl
		<< "  Escape........Exit" << endl << endl;
}

bool AiSimApp::processInput(const sf::Event& e, sf::Window& window, Simulator& sim)
{
	if (e.type == Event::KeyReleased)
	{
		if (e.key.code == Keyboard::Subtract || e.key.code == Keyboard::Dash)
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
		else if (e.key.code == Keyboard::Num3)
		{
			sim.drawAntPaths();
		}
		else if (e.key.code == Keyboard::Num4)
		{
			sim.drawDeadAnts();
		}
		else if (e.key.code == Keyboard::Num5)
		{
			drawBackground = !drawBackground;
		}
		else if (e.key.code == Keyboard::Slash)
		{
			printUserCommands();
		}
		else if (e.key.code == Keyboard::Escape)
		{
			window.close();
			return false;
		}
	}
	return true;
}