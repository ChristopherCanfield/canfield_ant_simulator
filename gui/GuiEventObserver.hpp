#pragma once

#include <SFML/Window/Event.hpp>

// Interface for an observer that wants to receive GUI events.
class GuiEventObserver
{
public:
	// Called when a subscribed event type occurs.
	virtual void onGuiEvent(const sf::Event& e) = 0;
};
