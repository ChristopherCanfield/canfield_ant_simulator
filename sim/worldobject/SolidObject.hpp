#pragma once

#include "../util/Typedefs.hpp"

#include <SFML/Graphics/Sprite.hpp>

#include <vector>
#include <memory>

// Christopher D. Canfield
// November 2013
// SolidObject.hpp


namespace cdc
{
	class Node;

	// Contains functions for creating impassable objects in the world. The functions
	// modify the nav graph, and return a sprite. The sprite should not be moved after
	// it is returned by these functions.
	class SolidObject
	{
	public:
		// Returns a sprite representing a rock.
		static sf::Sprite createRock(std::vector<Node>& navGraph, int left, int top);

		// Returns a sprite representing water.
		static sf::Sprite createWater(std::vector<Node>& navGraph, int left, int top);

	private:
		static sf::Texture* rockTexture;
		static sf::Texture* waterTexture;
	};
}