#include "StartSimButton.hpp"

// Christopher D. Canfield
// October 2013
// StartSimButton.hpp

using cdc::StartSimButton;
using cdc::GuiEventManager;
using cdc::Simulator;


StartSimButton::StartSimButton(GuiEventManager& eventManager, Simulator& simulator) :
	Button(eventManager), simulator(simulator)
{
	// TODO (2013-10-18): set button images.
}

StartSimButton::~StartSimButton()
{
}

void StartSimButton::onDirectGuiEvent(const sf::Event& e)
{
	Button::onDirectGuiEvent(e);
	if (e.type == sf::Event::MouseButtonReleased)
	{
		simulator.start();
	}
}