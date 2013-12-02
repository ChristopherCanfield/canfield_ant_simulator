#include "SolidObject.hpp"
#include "../nav/Node.hpp"

#include <SFML/Graphics.hpp>

#include <string>
#include <stdexcept>


// Christopher D. Canfield
// November 2013
// SolidObject.cpp


using namespace cdc;
using namespace std;

sf::Texture* SolidObject::rockTexture(nullptr);
sf::Texture* SolidObject::waterTexture(nullptr);


void removeBlockedEdges(vector<Node>& navGraph, float left, float top, float width, float height)
{
	sf::Rect<float> blockedRect(left, top, width, height);

	for (auto& node : navGraph)
	{
		if (blockedRect.intersects(node.getBoundingBox()))
		{
			while (!node.getEdgeList().empty())
			{
				node.removeEdge(node.getEdge(0), true);
			}
		}
	}
}

sf::Sprite cdc::SolidObject::createRock(vector<Node>& navGraph, int left, int top)
{
	const string path = "res/rock - stylized.png";

	if (rockTexture == nullptr)
	{
		rockTexture = new sf::Texture();
		rockTexture->loadFromFile(path);
	}

	if (rockTexture != nullptr)
	{
		auto sprite = sf::Sprite(*rockTexture);
		sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
		sprite.setPosition(left, top);
		removeBlockedEdges(navGraph, left - (sprite.getGlobalBounds().width / 2.f), 
				top - (sprite.getGlobalBounds().height / 2.f), 
				sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
		return sprite;
	}
	else
	{
		throw runtime_error("Unable to load rock file: " + path);
	}
}


sf::Sprite cdc::SolidObject::createWater(std::vector<Node>& navGraph, int left, int top)
{
	const string path = "res/water.png";

	if (waterTexture == nullptr)
	{
		waterTexture = new sf::Texture();
		waterTexture->loadFromFile(path);
	}

	if (waterTexture != nullptr)
	{
		auto sprite = sf::Sprite(*waterTexture);
		sprite.setPosition(left + (sprite.getGlobalBounds().width / 2.f), 
				top + (sprite.getGlobalBounds().height / 2.f));
		removeBlockedEdges(navGraph, left, top, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
		return sprite;
	}
	else
	{
		throw runtime_error("Unable to load water file: " + path);
	}
}