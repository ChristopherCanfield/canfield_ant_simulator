#include "GuiWidget.hpp"

// Christopher D. Canfield
// October 2013
// GuiWidget.cpp

using cdc::GuiWidget;


GuiWidget::GuiWidget()
{
}

void GuiWidget::setPosition(float x, float y)
{
	position.set(x, y);
}

void GuiWidget::setPosition(int x, int y)
{
	position.set(static_cast<float>(x), static_cast<float>(y));
}

const sf::Vector2f& GuiWidget::getPosition() const
{
	return position.get();
}

