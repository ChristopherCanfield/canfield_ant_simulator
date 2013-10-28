#include "PauseSimButton.hpp"

// Christopher D. Canfield
// October 2013
// PauseSimButton.hpp

using cdc::PauseSimButton;
using cdc::GuiEventManager;
using cdc::Simulator;


PauseSimButton::PauseSimButton(GuiEventManager& eventManager, Simulator& simulator) :
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


PauseSimButton::~PauseSimButton()
{
}


void PauseSimButton::onDirectGuiEvent(const sf::Event& e)
{
	Button::onDirectGuiEvent(e);
	if (e.type == sf::Event::MouseButtonReleased)
	{
		simulator.pause();
	}
}