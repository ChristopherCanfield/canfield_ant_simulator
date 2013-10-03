#pragma once

#include <SFML/Graphics/Rect.hpp>

// An object that wants to receive click events that are clicked 
// directly onto the object. Clickable objects should register with
// the GuiEventManager.
class Clickable
{
public:
	// The bounding box around the Clickable. Only clicks that fall within this
	// bounding box will be returned.
	virtual sf::IntRect getBoundingBox() = 0;
	// Called when a relevant click has been detected by the GuiEventManager.
	virtual void onClick() = 0;
};