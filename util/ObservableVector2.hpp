#pragma once

#include "Observable.hpp"

#include <SFML/System/Vector2.hpp>


namespace cdc
{

	class ObservableVector2 :
			public Observable<sf::Vector2f>
	{
	public:
		ObservableVector2();
		ObservableVector2(float x, float y);
		~ObservableVector2();

		void set(float x, float y);
		void set(int x, int y);
		void setX(float xy);
		void setY(float y);

		float getX() const;
		float getY() const;

		const sf::Vector2f& get() const;

	private:
		sf::Vector2f position;
	};
}