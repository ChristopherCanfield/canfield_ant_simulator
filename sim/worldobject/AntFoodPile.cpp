#include "AntFoodPile.hpp"

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
	sprite.setPosition(node.getPixelX(), node.getPixelY());
}


AntFoodPile::~AntFoodPile()
{
}


std::shared_ptr<AntFood> AntFoodPile::getFood()
{
	if (foodCount > 0)
	{
		--foodCount;
		auto food = std::make_shared<AntFood>(static_cast<float>(node->getPixelX()), 
				static_cast<float>(node->getPixelY()));
		return food;
	}
	return nullptr;
}

void AntFoodPile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}