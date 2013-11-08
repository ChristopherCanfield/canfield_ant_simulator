#pragma once

// Christopher D. Canfield
// October 2013
// GuiTestApp.hpp

#include "App.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../gui/button/DecreaseSimSpeedButton.hpp"
#include "../gui/button/IncreaseSimSpeedButton.hpp"
#include "../gui/button/PauseSimButton.hpp"
#include "../gui/button/StartSimButton.hpp"
#include "../gui/button/UnpauseSimButton.hpp"
#include "../sim/nav/Node.hpp"
#include "../sim/worldobject/AntFood.hpp"
#include "../sim/agent/Ant.hpp"
#include "../sim/agent/Spider.hpp"
#include "../gui/ViewManager.hpp"
#include "../sim/worldobject/AntFoodPile.hpp"
#include "../sim/worldobject/AntHome.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>
#include <list>


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
		UnpauseSimButton unpauseButton;
		StartSimButton startButton;
		PauseSimButton pauseButton;

		// Nodes.
		std::vector<Node> nodes;

		AntFoodPile* foodPile;
		AntHome antHome;

		// Ant food.
		std::vector<AntFood> food;

		// Ants.
		std::vector<std::shared_ptr<Ant>> ants;

		// Spider.
		std::vector<Spider*> spiders;

		ViewManager viewManager;
	};
}