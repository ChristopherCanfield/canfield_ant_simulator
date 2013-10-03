#pragma once

class GuiEventObserver;
class Clickable;

#include <SFML/Window/Event.hpp>

#include <vector>


// Manager for low-level GUI events.
class GuiEventManager
{
public:
	// Processes GUI events by notifying subscribed observers. This should be
	// called once per frame.
	void update(const sf::Event& e);
	// Registers the observer for click events.
	void addClickListener(const GuiEventObserver& o);
	// Unregisters the observer for click events.
	void removeClickListener(const GuiEventObserver& o);
	// Registers the observer for mouse move events
	void addMouseMoveListener(const GuiEventObserver& o);
	// Unregisters the observer for mouse move events.
	void removeMouseMoveListener(const GuiEventObserver& o);
	// Registers the observer for key press events.
	void addKeyPressListener(const GuiEventObserver& o);
	// Unregisters the observer for key press events.
	void removeKeyPressListener(const GuiEventObserver& o);
	// Registers the Clickable for click events that fall within its bounding box.
	void addDirectClickListener(const Clickable& c);
	// Unregisters the Clickable for the click events that fall within its bounding box.
	void removeDirectClickListener(const Clickable& c);

private:
	
	void notifySubscribers();
	// The list of click observers.
	std::vector<const GuiEventObserver*> clickObservers;
	// The list of mouse moved observers.
	std::vector<const GuiEventObserver*> mouseMoveObservers;
	// The list of key press observers.
	std::vector<const GuiEventObserver*> keyPressObservers;
	// The list of direct click observers.
	std::vector<const Clickable*> directClickObservers;
};

