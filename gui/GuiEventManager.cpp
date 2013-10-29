#include "GuiEventManager.hpp"
#include "GuiEventObserver.hpp"
#include "DirectGuiEventObserver.hpp"

// Christopher D. Canfield
// October 2013
// GuiEventManager.cpp


using cdc::GuiEventManager;
using cdc::DirectGuiEventObserver;
using cdc::GuiEventObserver;

// Passes the event to the GuiEventObservers in the referenced vector.
void notifyGuiEventObservers(const std::vector<GuiEventObserver*>& observers, const sf::Event& e);
// Passes the event to the observers in the referenced vector.
void notifyDirectGuiEventObservers(const std::vector<DirectGuiEventObserver*>& observers, const sf::Event& e);
// Removes the specified observer from the referenced vector if it is found in the container.
void removeIfMatchFound(std::vector<GuiEventObserver*>& observers, const GuiEventObserver& o);



void GuiEventManager::update(const sf::Event& e)
{
	if (e.type == sf::Event::MouseButtonReleased)
	{
		notifyDirectGuiEventObservers(directClickObservers, e);
		notifyGuiEventObservers(clickObservers, e);
	}
	else if (e.type == sf::Event::MouseMoved)
	{
		notifyDirectGuiEventObservers(directMouseMoveObservers, e);
		notifyGuiEventObservers(mouseMoveObservers, e);
	}
	else if (e.type == sf::Event::KeyPressed)
	{
		notifyGuiEventObservers(keyPressObservers, e);
	}
}


void GuiEventManager::addClickListener(GuiEventObserver& o)
{
	clickObservers.push_back(&o);
}

void GuiEventManager::removeClickListener(const GuiEventObserver& o)
{
	removeIfMatchFound(clickObservers, o);
}


void GuiEventManager::addMouseMoveListener(GuiEventObserver& o)
{
	mouseMoveObservers.push_back(&o);
}

void GuiEventManager::removeMouseMoveListener(const GuiEventObserver& o)
{
	removeIfMatchFound(mouseMoveObservers, o);
}


void GuiEventManager::addKeyPressListener(GuiEventObserver& o)
{
	keyPressObservers.push_back(&o);
}

void GuiEventManager::removeKeyPressListener(const GuiEventObserver& o)
{
	removeIfMatchFound(keyPressObservers, o);
}


void GuiEventManager::addDirectClickListener(DirectGuiEventObserver& o)
{
	directClickObservers.push_back(&o);
}

void GuiEventManager::removeDirectClickListener(const DirectGuiEventObserver& o)
{
	for (auto observer = directClickObservers.begin(); observer != directClickObservers.end();)
	{
		if (*observer == &o)
		{
			observer = directClickObservers.erase(observer);
		}
		else
		{
			++observer;
		}
	}
}


void GuiEventManager::addDirectMouseMoveListener(DirectGuiEventObserver& o)
{
	directMouseMoveObservers.push_back(&o);
}

void GuiEventManager::removeDirectMouseMoveListener(const DirectGuiEventObserver& o)
{
	for (auto observer = directMouseMoveObservers.begin(); observer != directMouseMoveObservers.end();)
	{
		if (*observer == &o)
		{
			observer = directMouseMoveObservers.erase(observer);
		}
		else
		{
			++observer;
		}
	}
}



void notifyGuiEventObservers(const std::vector<GuiEventObserver*>& observers, const sf::Event& e)
{
	for (auto observer : observers)
	{
		observer->onGuiEvent(e);
	}
}

void notifyDirectGuiEventObservers(const std::vector<DirectGuiEventObserver*>& observers, const sf::Event& e)
{
	float mouseX = static_cast<float>((e.type == sf::Event::MouseMoved) ? e.mouseMove.x : e.mouseButton.x);
	float mouseY = static_cast<float>((e.type == sf::Event::MouseMoved) ? e.mouseMove.y : e.mouseButton.y);

	for (auto observer : observers)
	{
		auto boundingBox = observer->getBoundingBox();
		// Call the observer's onClick method if the click fell within the observer's
		// bounding box.
		if (boundingBox.contains(mouseX, mouseY))
		{
			observer->onDirectGuiEvent(e);
		}
	}
}

void removeIfMatchFound(std::vector<GuiEventObserver*>& observers, const GuiEventObserver& o)
{
	for (auto observer = observers.begin(); observer != observers.end();)
	{
		if (*observer == &o)
		{
			observer = observers.erase(observer);
		}
		else
		{
			++observer;
		}
	}
}
