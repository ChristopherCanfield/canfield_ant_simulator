#pragma once

// Christopher D. Canfield
// October 2013
// AiSimApp.hpp

#include "App.hpp"
#include "../sim/Simulator.hpp"

#include <SFML/Window.hpp>


namespace cdc 
{

	class AiSimApp :
			public App
	{
	public:
		AiSimApp();
		virtual ~AiSimApp();

		virtual void setup() override;

		virtual bool run() override;

		virtual void teardown() override;

	private:
		sf::RenderWindow window;

		GuiEventManager eventManager;
		Simulator simulator;
	};

}