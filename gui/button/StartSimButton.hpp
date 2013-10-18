#pragma once

// Christopher D. Canfield
// October 2013
// StartSimButton.hpp

#include "../Button.hpp"
#include "../../sim/Simulator.hpp"

// A button that starts the simulation.
class StartSimButton :
		public Button
{
public:
	StartSimButton(GuiEventManager& eventManager, Simulator& simulator);
	~StartSimButton();

	virtual void onGuiEvent(const sf::Event& e) override;

private:
	Simulator& simulator;
};

