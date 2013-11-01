#include "ViewManager.hpp"
#include "../util/Vector2fAdapter.hpp"

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
	simView.setSize(Vector2fAdapter(simViewWidth, simViewHeight));
	simView.setCenter(simViewWidth / 2.f, simViewHeight / 2.f);

	uiView.setSize(Vector2fAdapter(uiViewWidth, uiViewHeight));
	uiView.setCenter(uiViewWidth / 2.f, uiViewHeight / 2.f);

	eventManager.addKeyPressListener(*this);
}


ViewManager::~ViewManager()
{
}

const sf::View& ViewManager::getSimView() const
{
	return simView;
}

void ViewManager::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}

void ViewManager::onGuiEvent(const sf::Event& e)
{
	// TODO: call moveMainView if key event.
	// TODO: zoom in or out if mouse wheel event.
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