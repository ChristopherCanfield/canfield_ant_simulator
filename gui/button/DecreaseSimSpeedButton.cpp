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
	using namespace std;
	using namespace sf;
	
	defaultTexture.loadFromFile("res/down_button_temp.png");
	onClickTexture.loadFromFile("res/down_button_temp_click.png");
	onHoverTexture.loadFromFile("res/down_button_temp_hover.png");

	setDefaultImage(unique_ptr<Sprite>(new Sprite(defaultTexture)));
	setOnClickImage(unique_ptr<Sprite>(new Sprite(onClickTexture)));
	setOnHoverImage(unique_ptr<Sprite>(new Sprite(onHoverTexture)));
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