#pragma once

#include "../util/Typedefs.hpp"
#include "../nav/Node.hpp"

#include <SFML/Graphics/Sprite.hpp>

#include <vector>
#include <memory>

// Christopher D. Canfield
// November 2013
// SolidObject.hpp


namespace cdc
{
	// Contains functions for creating impassable objects in the world. The functions
	// modify the nav graph, and return a sprite. The sprite should not be moved after
	// it is returned by these functions.
	namespace SolidObject
	{
		// Returns a sprite representing a rock.
		sf::Sprite createRock(std::vector<std::unique_ptr<Node>>& navGraph, int left, int top);

		// Returns a sprite representing water.
		sf::Sprite createWater(std::vector<std::unique_ptr<Node>>& navGraph, int left, int top);
	}
}