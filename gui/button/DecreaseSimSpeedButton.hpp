#pragma once

// Christopher D. Canfield
// October 2013
// DecreaseSimSpeedButton.hpp


#include "../Button.hpp"
#include "../../sim/Simulator.hpp"

namespace cdc 
{
	// A button that decreases the speed of the simulation.
	class DecreaseSimSpeedButton :
			public Button
	{
	public:
		DecreaseSimSpeedButton(GuiEventManager& eventManager, Simulator& simulator);
		~DecreaseSimSpeedButton();

		virtual void onDirectGuiEvent(const sf::Event& e) override;

	private:
		Simulator& simulator;
	};
}
