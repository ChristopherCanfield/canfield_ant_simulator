#include "RestartSimButton.hpp"

// Christopher D. Canfield
// October 2013
// RestartSimButton.hpp

using cdc::RestartSimButton;
using cdc::GuiEventManager;
using cdc::Simulator;


Restart::RestartSimButton(GuiEventManager& eventManager, Simulator& simulator) :
	Button(eventManager), simulator(simulator)
{
	// TODO (2013-10-18): set button images.
}

RestartSimButton::~RestartSimButton()
{
}

void RestartSimButton::onGuiEvent(const sf::Event& e)
{
	simulator.start();
}