#include "AntHome.hpp"
#include "../nav/Node.hpp"
#include "../util/Vector2fAdapter.hpp"

#include <cassert>
#include <iostream>

// Christopher D. Canfield
// November 2013
// AntHome.hpp

using cdc::AntHome;
using cdc::Node;

bool AntHome::wasTextureLoaded = false;
sf::Texture* AntHome::texture = nullptr;


AntHome::AntHome(Node& node) :
	foodCount(0),
	node(node)
{
	if (!AntHome::wasTextureLoaded)
	{
		if (AntHome::texture == nullptr)
		{
			AntHome::texture = new sf::Texture;
		}

		if (!AntHome::texture->loadFromFile("res/ant_hill.png"))
		{
			std::cout << "Unable to load ant hill image: res/ant_hill.png" << std::endl;
		}
		else
		{
			AntHome::wasTextureLoaded = true;
		}
	}

	sprite.setTexture(*AntHome::texture, true);
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
	sprite.setPosition(Vector2fAdapter(node.getPixelX(), node.getPixelY()));
}


AntHome::~AntHome()
{
}


uint AntHome::getFoodCount() const
{
	return foodCount;
}

bool AntHome::takeFood()
{
	if (foodCount > 0)
	{
		--foodCount;
		return true;
	}
	else
	{
		return false;
	}
}

void AntHome::addFood()
{
	++foodCount;
}


Node& AntHome::getNode() const
{
	return node;
}

void AntHome::update(uint ticks)
{
	// TODO: generate ants based on the amount of food.
	assert(false);
}

void AntHome::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}