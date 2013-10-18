#include "StopSimButton.hpp"

// Christopher D. Canfield
// October 2013
// StopSimButton.hpp


StopSimButton::StopSimButton(GuiEventManager& eventManager, Simulator& simulator) :
		Button(eventManager), simulator(simulator)
{
	// TODO (2013-10-18): set button images.
}


StopSimButton::~StopSimButton()
{
}


void StopSimButton::onGuiEvent(const sf::Event& e)
{
	simulator.stop();
}
