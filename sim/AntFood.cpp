#include "AntFood.hpp"

using cdc::AntFood;


AntFood::AntFood(float x, float y)
{
	shape.setRadius(5);
	shape.setOrigin(shape.getLocalBounds().width / 2.f, shape.getLocalBounds().height / 2.f);
	shape.setPosition(x, y);
	shape.setFillColor(sf::Color(38, 170, 0));
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(1.f);
}

AntFood::~AntFood()
{
}

const sf::Vector2f& AntFood::getPosition()
{
	return shape.getPosition();
}

void AntFood::setPosition(float x, float y)
{
	shape.setPosition(x, y);
}

void AntFood::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(shape, states);
}
