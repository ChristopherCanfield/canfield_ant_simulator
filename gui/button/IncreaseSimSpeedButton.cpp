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
	using namespace std;
	using namespace sf;
	
	defaultTexture.loadFromFile("res/up_button_temp.png");
	onClickTexture.loadFromFile("res/up_button_temp_click.png");
	onHoverTexture.loadFromFile("res/up_button_temp_hover.png");

	setDefaultImage(unique_ptr<Sprite>(new Sprite(defaultTexture)));
	setOnClickImage(unique_ptr<Sprite>(new Sprite(onClickTexture)));
	setOnHoverImage(unique_ptr<Sprite>(new Sprite(onHoverTexture)));
}

IncreaseSimSpeedButton::~IncreaseSimSpeedButton()
{
}

void IncreaseSimSpeedButton::onDirectGuiEvent(const sf::Event& e)
{
	Button::onDirectGuiEvent(e);
	if (e.type == sf::Event::MouseButtonReleased)
	{
		simulator.increaseSpeed();
	}
}