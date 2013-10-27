#pragma once

// Christopher D. Canfield
// October 2013
// AntFoodPile.hpp

#include "../util/Typedefs.hpp"
#include "AntFood.hpp"
#include "nav/Node.hpp"

#include <SFML/Graphics.hpp>

#include <memory>


namespace cdc
{

	class AntFoodPile :
			public sf::Drawable
	{
	public:
		AntFoodPile(uint foodCount, Node& node);
		~AntFoodPile();

		std::shared_ptr<AntFood> getFood();

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		static sf::Texture* texture;
		static bool wasTextureLoaded;

		uint foodCount;
		Node* node;

		sf::Sprite sprite;
	};
}
