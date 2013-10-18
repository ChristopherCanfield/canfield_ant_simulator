#pragma once

// Christopher D. Canfield
// October 2013
// IncreaseSimSpeedButton.hpp


#include "../Button.hpp"
#include "../../sim/Simulator.hpp"

// A button that increases the speed of the simulation.
class IncreaseSimSpeedButton :
		public Button
{
public:
	IncreaseSimSpeedButton(GuiEventManager& eventManager, Simulator& simulator);
	~IncreaseSimSpeedButton();

	virtual void onGuiEvent(const sf::Event& e) override;

private:
	Simulator& simulator;
};

