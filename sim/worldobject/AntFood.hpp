#pragma once

// Christopher D. Canfield
// October 2013
// AntFood.hpp


#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>


namespace cdc
{
	// A unit of ant food.
	class AntFood :
			public sf::Drawable
	{
	public:
		AntFood(float x, float y);
		~AntFood();

		const sf::Vector2f& getPosition();
		void setPosition(float x, float y);

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		sf::CircleShape shape;
	};
}
