#include "AntFoodPile.hpp"
#include "../util/Vector2fAdapter.hpp"

#include <iostream>

// Christopher D. Canfield
// October 2013
// AntFoodPile.cpp

using cdc::AntFoodPile;
using cdc::Node;
using cdc::AntFood;

bool AntFoodPile::wasTextureLoaded = false;
sf::Texture* AntFoodPile::texture = nullptr;


AntFoodPile::AntFoodPile(uint foodCount, Node& node) :
	node(&node),
	foodCount(foodCount)
{
	if (!AntFoodPile::wasTextureLoaded)
	{
		if (AntFoodPile::texture == nullptr)
		{
			AntFoodPile::texture = new sf::Texture;
		}

		if (!AntFoodPile::texture->loadFromFile("res/ant_food_pile.png"))
		{
			std::cout << "Unable to load ant food pile image: res/ant_food_pile.png" << std::endl;
		}
		else
		{
			AntFoodPile::wasTextureLoaded = true;
		}
	}

	sprite.setTexture(*AntFoodPile::texture, true);
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
	sprite.setPosition(Vector2fAdapter(node.getPixelX<uint>(), node.getPixelY<uint>()));

	node.setAntFoodPile(this);
}


AntFoodPile::~AntFoodPile()
{
	node->setAntFoodPile(nullptr);
}

uint AntFoodPile::getFoodCount() const
{
	return foodCount;
}

bool AntFoodPile::takeFood()
{
	if (foodCount > 0)
	{
		--foodCount;
		if (foodCount == 0)
		{
			node->setAntFoodPile(nullptr);
		}
		return true;
	}
	return false;
}

void AntFoodPile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}