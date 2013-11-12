#pragma once

#include <boost/noncopyable.hpp>

#include <vector>
#include <list>

// Christopher D. Canfield
// October 2013
// GuiEventManager.hpp

namespace sf 
{
	class Event;
	class RenderWindow;
}



namespace cdc 
{
	class GuiEventObserver;
	class DirectGuiEventObserver;

	// Manager for GUI events.
	class GuiEventManager :
			private boost::noncopyable
	{
	public:
		// Processes GUI events by notifying subscribed observers. This should be
		// called once per frame.
		void update(const sf::Event& e, const sf::RenderWindow& window);
	
		// Registers the observer for click events.
		void addClickListener(GuiEventObserver& o);
	
		// Unregisters the observer for click events.
		void removeClickListener(const GuiEventObserver& o);

		// Registers the observer for mouse move events.
		void addMouseMoveListener(GuiEventObserver& o);

		// Unregisters the observer for mouse move events.
		void removeMouseMoveListener(const GuiEventObserver& o);

		// Registers the observer for mouse wheel events.
		void addMouseWheelListener(GuiEventObserver& o);

		// Unregisters the observer for mouse wheel events.
		void removeMouseWheelListener(const GuiEventObserver& o);

		// Registers the observer for key press events.
		void addKeyPressListener(GuiEventObserver& o);

		// Unregisters the observer for key press events.
		void removeKeyPressListener(const GuiEventObserver& o);

		// Registers the DirectGuiEventObserver for click events that fall within its bounding box.
		void addDirectClickListener(DirectGuiEventObserver& o);

		// Unregisters the DirectGuiEventObserver for the click events that fall within its bounding box.
		void removeDirectClickListener(const DirectGuiEventObserver& o);

		// Registers the DirectGuiEventObserver for mouse move events that fall within its bounding box.
		void addDirectMouseMoveListener(DirectGuiEventObserver& o);

		// Unregisters the DirectGuiEventObserver for the mouse move events that fall within its bounding box.
		void removeDirectMouseMoveListener(const DirectGuiEventObserver& o);

	private:
		// The list of click observers.
		std::vector<GuiEventObserver*> clickObservers;
		// The list of mouse moved observers.
		std::vector<GuiEventObserver*> mouseMoveObservers;
		// The list of mouse move observers.
		std::vector<GuiEventObserver*> mouseWheelObservers;
		// The list of key press observers.
		std::vector<GuiEventObserver*> keyPressObservers;
		// The list of direct click observers.
		std::vector<DirectGuiEventObserver*> directClickObservers;
		// The list of direct mouse move observers.
		std::vector<DirectGuiEventObserver*> directMouseMoveObservers;
	};
}
