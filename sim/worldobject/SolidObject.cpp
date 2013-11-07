#include "SolidObject.hpp"

#include <SFML/Graphics.hpp>

#include <string>
#include <stdexcept>


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
		return  texture.loadFromFile(path);
	}

	return true;
}

void removeBlockedEdges(std::vector<Node>& navGraph, int left, int top, int width, int height)
{
	sf::Rect<int> blockedRect(left, top, width, height);

	for (auto node : navGraph)
	{
		sf::Rect<int> nodeRect(node.getPixelX() - 1, node.getPixelY() - 1, 2, 2);
		if (blockedRect.intersects(nodeRect))
		{
			auto edges = node.getEdgeList();
			edges.clear();
		}
	}
}


sf::Sprite SolidObject::createRock(std::vector<Node>& navGraph, int left, int top, int width, int height)
{
	const string path = "res/rock.png";

	if (loadTexture(rockTexture, path))
	{
		return sf::Sprite(rockTexture);
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
		return sf::Sprite(waterTexture);
	}
	else
	{
		throw runtime_error("Unable to load water file: " + path);
	}
}