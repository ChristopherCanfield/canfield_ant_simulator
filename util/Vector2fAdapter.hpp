#pragma once

#include "Typedefs.hpp"
#include <SFML/System/Vector2.hpp>


namespace cdc
{
	// An sf::Vector2f that takes 2 uints.
	class Vector2fAdapter :
			public sf::Vector2f
	{
	public:
		Vector2fAdapter(uint x, uint y);
	};
}