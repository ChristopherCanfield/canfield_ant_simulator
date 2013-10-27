#include "Ant.hpp"

#include <iostream>
#include <memory>

// Christopher D. Canfield
// October 2013
// Ant.cpp

using cdc::Ant;
using cdc::Percept;
using cdc::GuiEventManager;


bool Ant::wasTextureLoaded = false;
sf::Texture* Ant::texture = nullptr;


Ant::Ant(GuiEventManager& manager) :
		Button(manager)
{
	if (!Ant::wasTextureLoaded)
	{
		if (Ant::texture == nullptr)
		{
			Ant::texture = new sf::Texture;
		}

		if (!Ant::texture->loadFromFile("res/ant.png"))
		{
			std::cout << "Unable to load ant image: res/ant.png" << std::endl;
		}
		else
		{
			Ant::wasTextureLoaded = true;
		}
	}

	auto antSprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(*Ant::texture));			
	setDefaultImage(std::move(antSprite));

	// Ants don't need to know about mouse move events or indirect click events.
	manager.removeMouseMoveListener(*this);
	manager.removeClickListener(*this);
}

Ant::Ant(Ant&& other) :
	Button(std::move(other))
{
}

Ant::~Ant()
{
}

void Ant::update(const Percept& percept)
{

}

void Ant::onDirectGuiEvent(const sf::Event& e)
{

}