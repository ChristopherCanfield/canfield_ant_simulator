#pragma once

// Christopher D. Canfield
// October 2013
// UnpauseSimButton.hpp

#include "../Button.hpp"
#include "../../sim/Simulator.hpp"

namespace cdc 
{
	// A button that starts the simulation.
	class UnpauseSimButton :
			public Button
	{
	public:
		UnpauseSimButton(GuiEventManager& eventManager, Simulator& simulator);
		~UnpauseSimButton();

		virtual void onDirectGuiEvent(const sf::Event& e) override;

	private:
		Simulator& simulator;
	};
}