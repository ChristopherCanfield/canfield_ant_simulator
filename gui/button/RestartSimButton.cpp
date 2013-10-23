#include "RestartSimButton.hpp"

// Christopher D. Canfield
// October 2013
// RestartSimButton.hpp

using cdc::RestartSimButton;
using cdc::GuiEventManager;
using cdc::Simulator;


RestartSimButton::RestartSimButton(GuiEventManager& eventManager, Simulator& simulator) :
	Button(eventManager), simulator(simulator)
{
	using namespace std;
	using namespace sf;
	
	defaultTexture.loadFromFile("res/play_button_temp.png");
	onClickTexture.loadFromFile("res/play_button_temp_click.png");
	onHoverTexture.loadFromFile("res/play_button_temp_hover.png");

	setDefaultImage(unique_ptr<Sprite>(new Sprite(defaultTexture)));
	setOnClickImage(unique_ptr<Sprite>(new Sprite(onClickTexture)));
	setOnHoverImage(unique_ptr<Sprite>(new Sprite(onHoverTexture)));
}

RestartSimButton::~RestartSimButton()
{
}


void RestartSimButton::onDirectGuiEvent(const sf::Event& e)
{
	Button::onDirectGuiEvent(e);
	if (e.type == sf::Event::MouseButtonReleased)
	{
		simulator.restart();
	}
}