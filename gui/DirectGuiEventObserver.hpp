#pragma once

// Christopher D. Canfield
// October 2013
// DirectGuiEventObserver.cpp

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Event.hpp>

namespace cdc 
{
	// An object that wants to receive events that occur directly within the bounding box
	// of the object. DirectGuiEventObserver objects should register with the GuiEventManager.
	class DirectGuiEventObserver
	{
	public:
		// The bounding box around the DirectGuiEventObserver. Only events that fall within this
		// bounding box will be returned.
		virtual sf::IntRect getBoundingBox() = 0;
		// Called when a relevant gui event has been detected by the manager.
		virtual void onDirectGuiEvent(const sf::Event& e) = 0;
	};
}
