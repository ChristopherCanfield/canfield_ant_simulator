#include "SolidObject.hpp"

#include <SFML/Graphics.hpp>

#include <string>


// Christopher D. Canfield
// November 2013
// SolidObject.cpp


using namespace cdc;
using namespace std;

static sf::Texture rockTexture;
static sf::Texture waterTexture;


bool loadTexture(sf::Texture& texture, string path)
{
	if (texture.getSize() == sf::Vector2u())
	{
		// load image.
	}

	// return true if texture was loaded, or false if not.
}


sf::Sprite SolidObject::createRock(std::vector<Node>& navGraph, uint top, uint left, uint width, uint height)
{
	const string path = "res/rock.png";

	// TODO: create and return the sprite.
}


sf::Sprite SolidObject::createWater(std::vector<Node>& navGraph, uint top, uint left, uint width, uint height)
{
	const string path = "res/water.png";

	// TODO: create and return the sprite.
}