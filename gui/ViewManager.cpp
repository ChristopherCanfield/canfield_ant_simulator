#include "ViewManager.hpp"

#include <iostream>
#include <iomanip>

// Christopher D. Canfield
// October 2013
// ViewManager.cpp

using cdc::ViewManager;
using cdc::GuiEventManager;


ViewManager::ViewManager(GuiEventManager& eventManager, uint worldWidth, uint worldHeight, uint viewWidth, uint viewHeight) :
	worldWidth(worldWidth), 
	worldHeight(worldHeight)
{
	view.setSize(static_cast<float>(viewWidth), static_cast<float>(viewHeight));
	view.setCenter(viewWidth / 2.f, viewHeight / 2.f);

	eventManager.addKeyPressListener(*this);
}


ViewManager::~ViewManager()
{
}

const sf::View& ViewManager::getView() const
{
	return view;
}

void ViewManager::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}

void ViewManager::onGuiEvent(const sf::Event& e)
{
	const float movementAmount = 25.f;

	if (e.key.code == sf::Keyboard::Left)
	{
		if (view.getCenter().x > view.getSize().x / 2.f)
		{
			std::cout << "Left" << std::endl;
			view.move(-movementAmount, 0.f);
			window->setView(view);
		}
	}
	else if (e.key.code == sf::Keyboard::Right)
	{
		if (view.getCenter().x < (worldWidth - view.getSize().x / 2.f))
		{
			std::cout << "Right" << std::endl;
			view.move(movementAmount, 0.f);
			window->setView(view);
		}
	}
	else if (e.key.code == sf::Keyboard::Up)
	{
		if (view.getCenter().y > view.getSize().y / 2.f)
		{
			std::cout << "Up" << std::endl;
			view.move(0.f, -movementAmount);
			window->setView(view);
		}
	}
	else if (e.key.code == sf::Keyboard::Down)
	{
		if (view.getCenter().y < (worldHeight - view.getSize().y / 2.f))
		{
			std::cout << "Down" << std::endl;
			view.move(0.f, movementAmount);
			window->setView(view);
		}
	}
}