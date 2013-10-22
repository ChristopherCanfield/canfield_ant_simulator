#pragma once

#include "App.hpp"
#include "../gui/GuiEventManager.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

// Tests the gui functionality.
class GuiTestApp :
		public App
{
public:
	GuiTestApp();
	virtual ~GuiTestApp();

	virtual void setup() override;
	virtual bool run() override;
	virtual void teardown() override;

private:
	std::unique_ptr<sf::RenderWindow> window;

	cdc::GuiEventManager eventManager;
};

