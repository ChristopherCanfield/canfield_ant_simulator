#include "StartSimButton.hpp"
#include "../sim/world/RandomWorld.hpp"

// Christopher D. Canfield
// October 2013
// StartSimButton.hpp

using cdc::StartSimButton;
using cdc::GuiEventManager;
using cdc::Simulator;

using std::unique_ptr;


StartSimButton::StartSimButton(GuiEventManager& eventManager, Simulator& simulator) :
	Button(eventManager), 
	simulator(simulator),
	eventManager(eventManager)
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

StartSimButton::~StartSimButton()
{
}

void StartSimButton::onDirectGuiEvent(const sf::Event& e)
{
	Button::onDirectGuiEvent(e);
	if (e.type == sf::Event::MouseButtonReleased)
	{
		unique_ptr<World> world = unique_ptr<World>(new RandomWorld(eventManager));
		simulator.start(move(world));
	}
}