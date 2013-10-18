#include "GuiWidget.hpp"

// Christopher D. Canfield
// October 2013
// GuiWidget.cpp


void GuiWidget::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

void GuiWidget::setPosition(int x, int y)
{
	position.x = static_cast<float>(x);
	position.y = static_cast<float>(y);
}

const sf::Vector2f& GuiWidget::getPosition() const
{
	return position;
}