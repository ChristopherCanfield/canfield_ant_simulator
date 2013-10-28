#pragma once

// Christopher D. Canfield
// October 2013
// PauseSimButton.hpp

#include "../Button.hpp"
#include "../../sim/Simulator.hpp"

namespace cdc 
{
	// A button that stops the simulation.
	class PauseSimButton :
			public Button
	{
	public:
		PauseSimButton(GuiEventManager& eventManager, Simulator& simulator);
		~PauseSimButton();

		virtual void onDirectGuiEvent(const sf::Event& e) override;

	private:
		Simulator& simulator;
	};
}
