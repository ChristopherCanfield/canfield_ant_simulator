#pragma once

// Christopher D. Canfield
// October 2013
// StopSimButton.hpp

#include "../Button.hpp"
#include "../../sim/Simulator.hpp"

namespace cdc 
{
	// A button that stops the simulation.
	class StopSimButton :
			public Button
	{
	public:
		StopSimButton(GuiEventManager& eventManager, Simulator& simulator);
		~StopSimButton();

		virtual void onDirectGuiEvent(const sf::Event& e) override;

	private:
		Simulator& simulator;
	};
}