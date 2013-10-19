#pragma once

// Christopher D. Canfield
// October 2013
// RestartSimButton.hpp

#include "../Button.hpp"
#include "../../sim/Simulator.hpp"

namespace cdc 
{
	// A button that starts the simulation.
	class RestartSimButton :
			public Button
	{
	public:
		RestartSimButton(GuiEventManager& eventManager, Simulator& simulator);
		~RestartSimButton();

		virtual void onGuiEvent(const sf::Event& e) override;
		virtual void onDirectGuiEvent(const sf::Event& e) override;

	private:
		Simulator& simulator;
	};
}