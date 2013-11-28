#include "ViewManager.hpp"
#include "../util/Vector2fAdapter.hpp"

#include <Poco/UUIDGenerator.h>

#include <iostream>
#include <iomanip>

// Christopher D. Canfield
// October 2013
// ViewManager.cpp

using cdc::ViewManager;
using cdc::GuiEventManager;


ViewManager::ViewManager(GuiEventManager& eventManager, 
						 uint worldWidth, uint worldHeight, 
						 uint simViewWidth, uint simViewHeight,
						 uint uiViewWidth, uint uiViewHeight) :
	worldWidth(worldWidth), 
	worldHeight(worldHeight)
{
	Poco::UUIDGenerator& generator = Poco::UUIDGenerator::defaultGenerator();
	id = generator.createRandom();

	simView.setSize(Vector2fAdapter(simViewWidth, simViewHeight));
	simView.setCenter(simViewWidth / 2.f, simViewHeight / 2.f);

	uiView.setSize(Vector2fAdapter(uiViewWidth, uiViewHeight));
	uiView.setCenter(uiViewWidth / 2.f, uiViewHeight / 2.f);

	eventManager.addKeyPressListener(*this);
	eventManager.addMouseWheelListener(*this);
}


ViewManager::~ViewManager()
{
}

sf::View& ViewManager::getSimView()
{
	return simView;
}

sf::View& ViewManager::getUiView()
{
	return uiView;
}

void ViewManager::setWindow(sf::RenderWindow& window)
{
	this->window = &window;
}

void ViewManager::onGuiEvent(const sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		moveMainView(e);
	}
	else if (e.type == sf::Event::MouseWheelMoved)
	{
		if (e.mouseWheel.delta > 0)
		{
			simView.zoom(0.95f);
		}
		else if (e.mouseWheel.delta < 0)
		{
			simView.zoom(1.05f);
		}

		window->setView(simView);
	}
}

Poco::UUID ViewManager::getObserverId() const
{
	return id;
}


void ViewManager::moveMainView(const sf::Event& e)
{
	const float movementAmount = 25.f;

	if (e.key.code == sf::Keyboard::Left)
	{
		if (simView.getCenter().x > simView.getSize().x / 2.f)
		{
			std::cout << "Left" << std::endl;
			simView.move(-movementAmount, 0.f);
			window->setView(simView);
		}
	}
	else if (e.key.code == sf::Keyboard::Right)
	{
		if (simView.getCenter().x < (worldWidth - simView.getSize().x / 2.f))
		{
			std::cout << "Right" << std::endl;
			simView.move(movementAmount, 0.f);
			window->setView(simView);
		}
	}
	else if (e.key.code == sf::Keyboard::Up)
	{
		if (simView.getCenter().y > simView.getSize().y / 2.f)
		{
			std::cout << "Up" << std::endl;
			simView.move(0.f, -movementAmount);
			window->setView(simView);
		}
	}
	else if (e.key.code == sf::Keyboard::Down)
	{
		if (simView.getCenter().y < (worldHeight - simView.getSize().y / 2.f))
		{
			std::cout << "Down" << std::endl;
			simView.move(0.f, movementAmount);
			window->setView(simView);
		}
	}
}