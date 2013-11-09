#include "SolidObject.hpp"

#include <SFML/Graphics.hpp>

#include <string>
#include <stdexcept>


// Christopher D. Canfield
// November 2013
// SolidObject.cpp


using namespace cdc;
using namespace std;

static sf::Texture* rockTexture;
static sf::Texture* waterTexture;


bool loadTexture(sf::Texture* texture, string path)
{
	if (texture == nullptr)
	{
		try
		{
			texture = new sf::Texture();
			return  texture->loadFromFile(path);
		}
		catch (...)
		{
			return false;
		}
	}

	return true;
}

void removeBlockedEdges(std::vector<Node>& navGraph, int left, int top, int width, int height)
{
	sf::Rect<int> blockedRect(left, top, width, height);

	for (auto node : navGraph)
	{
		if (blockedRect.intersects(node.getBoundingBox()))
		{
			auto edges = node.getEdgeList();
			edges.clear();
		}
	}
}


sf::Sprite SolidObject::createRock(std::vector<Node>& navGraph, int left, int top)
{
	const string path = "res/rock.png";

	if (loadTexture(rockTexture, path))
	{
		auto sprite = sf::Sprite(*rockTexture);
		sprite.setPosition(left + (sprite.getGlobalBounds().width / 2.f), 
				top + (sprite.getGlobalBounds().height / 2.f));
		removeBlockedEdges(navGraph, left, top, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
		return sprite;
	}
	else
	{
		throw runtime_error("Unable to load rock file: " + path);
	}
}


sf::Sprite SolidObject::createWater(std::vector<Node>& navGraph, int left, int top, int width, int height)
{
	const string path = "res/water.png";

	if (loadTexture(rockTexture, path))
	{
		auto sprite = sf::Sprite(*waterTexture);
		sprite.setPosition(left + (width / 2.f), top + (height / 2.f));
		removeBlockedEdges(navGraph, left, top, width, height);
		return sprite;
	}
	else
	{
		throw runtime_error("Unable to load water file: " + path);
	}
}