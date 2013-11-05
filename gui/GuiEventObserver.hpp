#pragma once

// Christopher D. Canfield
// October 2013
// GuiEventObserver.hpp

#include <SFML/Window/Event.hpp>

namespace cdc 
{
	// Interface for an observer that wants to receive GUI events.
	class GuiEventObserver
	{
	public:
		virtual ~GuiEventObserver() {}

		// Called when a subscribed event type occurs.
		virtual void onGuiEvent(const sf::Event& e) = 0;
	};
}