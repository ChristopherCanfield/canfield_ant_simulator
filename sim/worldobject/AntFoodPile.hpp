#pragma once

// Christopher D. Canfield
// October 2013
// AntFoodPile.hpp

#include "../../util/Typedefs.hpp"
#include "AntFood.hpp"
#include "../nav/Node.hpp"

#include <SFML/Graphics.hpp>

#include <memory>


namespace cdc
{

	class AntFoodPile :
			public sf::Drawable
	{
	public:
		AntFoodPile(uint foodCount, Node& node);
		virtual ~AntFoodPile();

		// Returns the amount of food remaining in the pile.
		uint getFoodCount() const;

		// Returns true if food was successfully taken, or false if not 
		// (i.e., no food is available).
		bool takeFood();

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		static sf::Texture* texture;
		static bool wasTextureLoaded;

		uint foodCount;
		Node* node;

		sf::Sprite sprite;
	};
}
