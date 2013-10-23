#include "ObservableVector2.hpp"


using cdc::ObservableVector2;



ObservableVector2::ObservableVector2()
{
}

ObservableVector2::ObservableVector2(float x, float y)
{
	position.x = x;
	position.y = y;
	notifyObservers(position);
}

ObservableVector2::~ObservableVector2()
{
}

void ObservableVector2::set(float x, float y)
{
	position.x = x;
	position.y = y;
	notifyObservers(position);
}

void ObservableVector2::setX(float x)
{
	position.x = x;
	notifyObservers(position);
}

void ObservableVector2::setY(float y)
{
	position.y = y;
	notifyObservers(position);
}

float ObservableVector2::getX() const
{
	return position.x;
}

float ObservableVector2::getY() const
{
	return position.y;
}

const sf::Vector2f& ObservableVector2::get() const
{
	return position;
}