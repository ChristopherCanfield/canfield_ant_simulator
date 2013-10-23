#include "StopSimButton.hpp"

// Christopher D. Canfield
// October 2013
// StopSimButton.hpp

using cdc::StopSimButton;
using cdc::GuiEventManager;
using cdc::Simulator;


StopSimButton::StopSimButton(GuiEventManager& eventManager, Simulator& simulator) :
		Button(eventManager), simulator(simulator)
{
	using namespace std;
	using namespace sf;
	
	defaultTexture.loadFromFile("res/pause_button_temp.png");
	onClickTexture.loadFromFile("res/pause_button_temp_click.png");
	onHoverTexture.loadFromFile("res/pause_button_temp_hover.png");

	setDefaultImage(unique_ptr<Sprite>(new Sprite(defaultTexture)));
	setOnClickImage(unique_ptr<Sprite>(new Sprite(onClickTexture)));
	setOnHoverImage(unique_ptr<Sprite>(new Sprite(onHoverTexture)));
}


StopSimButton::~StopSimButton()
{
}


void StopSimButton::onDirectGuiEvent(const sf::Event& e)
{
	Button::onDirectGuiEvent(e);
	if (e.type == sf::Event::MouseButtonReleased)
	{
		simulator.stop();
	}
}