#include "StartSimButton.hpp"

// Christopher D. Canfield
// October 2013
// StartSimButton.hpp



StartSimButton::StartSimButton(GuiEventManager& eventManager, Simulator& simulator) :
	Button(eventManager), simulator(simulator)
{
	// TODO (2013-10-18): set button images.
}

StartSimButton::~StartSimButton()
{
}

void StartSimButton::onGuiEvent(const sf::Event& e)
{
	simulator.start();
}