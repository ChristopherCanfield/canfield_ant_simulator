#include "GuiTestApp.hpp"

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <iomanip>

// Christopher D. Canfield
// October 2013
// GuiTestApp.cpp


using cdc::GuiTestApp;


GuiTestApp::GuiTestApp() :
	decreaseSpeedButton(eventManager, simulator),
	increaseSpeedButton(eventManager, simulator),
	unpauseButton(eventManager, simulator),
	startButton(eventManager, simulator),
	pauseButton(eventManager, simulator),
	viewManager(eventManager, 1000, 1000, 800, 800, 200, 800),
	simulator(eventManager)
{
	using namespace std;

	nodes.push_back(Node(GridLocation(0, 0), 10, 10));
	nodes.push_back(Node(GridLocation(0, 0), 40, 10));
	nodes.push_back(Node(GridLocation(0, 0), 40, 40));
	nodes.push_back(Node(GridLocation(0, 0), 10, 40));
	nodes.push_back(Node(GridLocation(0, 0), 10, 80));

	auto edge01 = make_shared<Edge>(nodes[0], nodes[1], 10);
	auto edge12 = make_shared<Edge>(nodes[1], nodes[2], 10);
	auto edge23 = make_shared<Edge>(nodes[2], nodes[3], 10);
	auto edge30 = make_shared<Edge>(nodes[3], nodes[0], 10);
	auto edge34 = make_shared<Edge>(nodes[3], nodes[4], 10);

	nodes[0].addEdge(edge01).addEdge(edge30);
	nodes[1].addEdge(edge01).addEdge(edge12);
	nodes[2].addEdge(edge12).addEdge(edge23);
	nodes[3].addEdge(edge23).addEdge(edge30).addEdge(edge34);
	nodes[4].addEdge(edge34);

	food.push_back(AntFood(60.f, 60.f));

	auto ant1 = std::make_shared<Ant>(eventManager);
	auto ant2 = std::make_shared<Ant>(eventManager);
	ants.push_back(ant1);
	ants.push_back(ant2);
	ant1->setPosition(40, 200);
	ant2->setPosition(40, 300);

	spiders.push_back(new Spider(eventManager));
	spiders[0]->setPosition(40, 400);

	foodPile = new AntFoodPile(10, nodes[4]);
}


GuiTestApp::~GuiTestApp()
{
}


void GuiTestApp::setup()
{
	window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(800, 800), "GUI Tests"));
	window->setFramerateLimit(60);

	decreaseSpeedButton.setPosition(50, 50);
	increaseSpeedButton.setPosition(150, 150);
	startButton.setPosition(250, 250);
	unpauseButton.setPosition(350, 350);
	pauseButton.setPosition(25, 450);

	viewManager.setWindow(window.get());
	viewManager.getSimView().setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	//viewManager.getUiView().setViewport(sf::FloatRect(0.f, 0.f, 1.f, 0.2f));
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

	window->setView(viewManager.getSimView());

	window->draw(decreaseSpeedButton);
	window->draw(increaseSpeedButton);
	window->draw(startButton);
	window->draw(unpauseButton);
	window->draw(pauseButton);

	for (auto& node : nodes)
	{
		for (auto edge : node.getEdgeList())
		{
			window->draw(*edge);
		}
		window->draw(node);
	}

	for (auto& f : food)
	{
		window->draw(f);
	}

	for (auto& ant : ants)
	{
		window->draw(*ant);
	}

	for (auto& spider : spiders)
	{
		window->draw(*spider);
	}

	window->draw(*foodPile);

	window->display();

	return true;
}


void GuiTestApp::teardown()
{
}
