#include "Ant.hpp"
#include "../nav/Node.hpp"
#include "../worldobject/AntHome.hpp"

#include <iostream>
#include <memory>

// Christopher D. Canfield
// October 2013
// Ant.cpp

using cdc::Ant;
using cdc::Percept;
using cdc::GuiEventManager;
using cdc::Node;
using cdc::AntHome;


bool Ant::wasTextureLoaded = false;
sf::Texture* Ant::texture = nullptr;


Ant::Ant(GuiEventManager& manager, AntHome& home) :
		Button(manager),
		kb(home)
{
	if (!Ant::wasTextureLoaded)
	{
		if (Ant::texture == nullptr)
		{
			Ant::texture = new sf::Texture;
		}

		if (!Ant::texture->loadFromFile("res/ant.png"))
		{
			std::cout << "Unable to load ant image: res/ant.png" << std::endl;
		}
		else
		{
			Ant::wasTextureLoaded = true;
		}
	}

	auto antSprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(*Ant::texture));			
	setDefaultImage(std::move(antSprite));

	// Ants don't need to know about mouse move events or indirect click events.
	manager.removeMouseMoveListener(*this);
	manager.removeClickListener(*this);
}

Ant::Ant(Ant&& other) :
	Button(std::move(other)),
	kb(std::move(other.kb)),
	stats(other.stats)
{
}

Ant::~Ant()
{
}

void Ant::update(long ticks, const Percept& percept)
{

}

Node* Ant::getLastKnownFoodPosition() const
{
	return kb.lastKnownFoodPosition;
}

uint Ant::getHunger() const
{
	return stats.hunger;
}

AntHome& Ant::getHome() const
{
	return kb.home;
}

bool Ant::isDead() const
{
	return stats.isDead;
}

void Ant::kill()
{
	stats.isDead = true;
}

Node* Ant::getNode() const
{
	return kb.lastNodePassed;
}



void Ant::onDirectGuiEvent(const sf::Event& e)
{
	
}


Ant::AntKnowledgeBase::AntKnowledgeBase(AntHome& home) :
	home(home),
	lastKnownFoodPosition(nullptr),
	lastNodePassed(nullptr)
{
}

Ant::AntStats::AntStats() :
	hungerIncreaseRate(120),	// default ticks per second is 30, so this gives a rate of 4 seconds per increase in hunger.
	hunger(0),
	isHoldingFood(false),
	isDead(false)
{
}