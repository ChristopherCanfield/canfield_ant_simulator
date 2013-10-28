#include "UnpauseSimButton.hpp"

// Christopher D. Canfield
// October 2013
// UnpauseSimButton.hpp

using cdc::UnpauseSimButton;
using cdc::GuiEventManager;
using cdc::Simulator;


UnpauseSimButton::UnpauseSimButton(GuiEventManager& eventManager, Simulator& simulator) :
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

UnpauseSimButton::~UnpauseSimButton()
{
}


void UnpauseSimButton::onDirectGuiEvent(const sf::Event& e)
{
	Button::onDirectGuiEvent(e);
	if (e.type == sf::Event::MouseButtonReleased)
	{
		simulator.unpause();
	}
}