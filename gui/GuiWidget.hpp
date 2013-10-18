#pragma once

// Christopher D. Canfield
// October 2013
// GuiWidget.hpp

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>


// Base class for GUI widgets.
class GuiWidget :
		public sf::Drawable
{
public:
	GuiWidget() {}
	virtual ~GuiWidget() {}
	void setPosition(float x, float y);
	void setPosition(int x, int y);
	const sf::Vector2f& getPosition() const;
	
private:
	sf::Vector2f position;
};