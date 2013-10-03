#include "GuiEventManager.hpp"


// Passes the event to the GuiEventObservers in the referenced vector.
void notifyGuiEventObservers(const std::vector<const GuiEventObserver*>& observers, const sf::Event& e);
// Passes the event to the Clickable observers in the referenced vector.
void notifyDirectClickObservers(const std::vector<const Clickable*>& observers, const sf::Event& e);


GuiEventManager::GuiEventManager()
{
}

