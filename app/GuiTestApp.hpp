#pragma once

#include "App.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../gui/button/DecreaseSimSpeedButton.hpp"
#include "../gui/button/IncreaseSimSpeedButton.hpp"
#include "../gui/button/RestartSimButton.hpp"
#include "../gui/button/StartSimButton.hpp"
#include "../gui/button/StopSimButton.hpp"

#include <SFML/Graphics.hpp>

#include <memory>


namespace cdc 
{
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

		GuiEventManager eventManager;
		Simulator simulator;

		// Gui elements.
		DecreaseSimSpeedButton decreaseSpeedButton;
		IncreaseSimSpeedButton increaseSpeedButton;
		RestartSimButton restartButton;
		StartSimButton startButton;
		StopSimButton stopButton;
	};
}