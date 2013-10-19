#include "IncreaseSimSpeedButton.hpp"

// Christopher D. Canfield
// October 2013
// IncreaseSimSpeedButton.hpp

using cdc::IncreaseSimSpeedButton;
using cdc::GuiEventManager;
using cdc::Simulator;


IncreaseSimSpeedButton::IncreaseSimSpeedButton(GuiEventManager& eventManager, Simulator& simulator) :
	Button(eventManager), simulator(simulator)
{
	// TODO (2013-10-18): set button images.
}

IncreaseSimSpeedButton::~IncreaseSimSpeedButton()
{
}

void IncreaseSimSpeedButton::onGuiEvent(const sf::Event& e)
{
	simulator.increaseSpeed();
}