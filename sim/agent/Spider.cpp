#include "Spider.hpp"

#include <iostream>
#include <memory>

// Christopher D. Canfield
// October 2013
// Spider.cpp


using cdc::Spider;
using cdc::Percept;
using cdc::GuiEventManager;


bool Spider::wasTextureLoaded = false;
sf::Texture* Spider::texture = nullptr;


Spider::Spider(GuiEventManager& manager) :
		Button(manager)
{
	if (!Spider::wasTextureLoaded)
	{
		if (Spider::texture == nullptr)
		{
			Spider::texture = new sf::Texture;
		}

		if (!Spider::texture->loadFromFile("res/spider.png"))
		{
			std::cout << "Unable to load spider image: res/spider.png";
		}
		else
		{
			auto spiderSprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(*Spider::texture));
			setDefaultImage(std::move(spiderSprite));
			Spider::wasTextureLoaded = true;
		}
	}

	// Ants don't need to know about mouse move events or indirect click events.
	manager.removeMouseMoveListener(*this);
	manager.removeClickListener(*this);
}

Spider::~Spider()
{

}

void Spider::update(const Percept& percept)
{

}

void Spider::onDirectGuiEvent(const sf::Event& e)
{

}