#pragma once

// Christopher D. Canfield
// October 2013
// GuiEventObserver.hpp

#include <SFML/Window/Event.hpp>

namespace Poco
{
	class UUID;
}

namespace cdc 
{
	// Interface for an observer that wants to receive GUI events.
	class GuiEventObserver
	{
	public:
		virtual ~GuiEventObserver() {}

		// Called when a subscribed event type occurs.
		virtual void onGuiEvent(const sf::Event& e) = 0;

		// Returns a unique ID that is used to identify observers.
		virtual Poco::UUID getObserverId() const = 0;
	};
}