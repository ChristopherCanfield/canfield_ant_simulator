#include "DecreaseSimSpeedButton.hpp"

// Christopher D. Canfield
// October 2013
// DecreaseSimSpeedButton.hpp

using cdc::DecreaseSimSpeedButton;
using cdc::GuiEventManager;
using cdc::Simulator;


DecreaseSimSpeedButton::DecreaseSimSpeedButton(GuiEventManager& eventManager, Simulator& simulator) :
	Button(eventManager), simulator(simulator)
{
	// TODO (2013-10-18): set button images.
}

DecreaseSimSpeedButton::~DecreaseSimSpeedButton()
{
}


void DecreaseSimSpeedButton::onDirectGuiEvent(const sf::Event& e)
{
	Button::onDirectGuiEvent(e);
	if (e.type == sf::Event::MouseButtonReleased)
	{
		simulator.decreaseSpeed();
	}
}