#include "AntHome.hpp"
#include "../nav/Node.hpp"
#include "../util/Vector2fAdapter.hpp"
#include "../Simulator.hpp"

#include <cassert>
#include <iostream>

// Christopher D. Canfield
// November 2013
// AntHome.hpp

using cdc::AntHome;
using cdc::Node;
using cdc::NavGraphHelper;
using cdc::Simulator;

bool AntHome::wasTextureLoaded = false;
sf::Texture* AntHome::texture = nullptr;

const uint antIncreaseRate = Simulator::defaultTicksPerSecond * 10;
const uint foodPerAnt = 10;


AntHome::AntHome(Node& node, std::vector<Node>& navGraph, World& world) :
	foodCount(0),
	node(node),
	navGraphHelper(navGraph),
	nextAntCreatedTick(antIncreaseRate),
	world(world)
{
	if (!AntHome::wasTextureLoaded)
	{
		if (AntHome::texture == nullptr)
		{
			AntHome::texture = new sf::Texture;
		}

		if (!AntHome::texture->loadFromFile("res/ant_hill.png"))
		{
			std::cout << "Unable to load ant hill image: res/ant_hill.png" << std::endl;
		}
		else
		{
			AntHome::wasTextureLoaded = true;
		}
	}

	sprite.setTexture(*AntHome::texture, true);
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
	sprite.setPosition(Vector2fAdapter(node.getPixelX(), node.getPixelY()));
}


AntHome::~AntHome()
{
}


uint AntHome::getFoodCount() const
{
	return foodCount;
}

bool AntHome::takeFood()
{
	if (foodCount > 0)
	{
		--foodCount;
		return true;
	}
	else
	{
		return false;
	}
}

void AntHome::addFood()
{
	++foodCount;
}


Node& AntHome::getNode() const
{
	return node;
}

NavGraphHelper& AntHome::getNavGraphHelper()
{
	return navGraphHelper;
}

void AntHome::update(uint ticks)
{
	if (nextAntCreatedTick < ticks)
	{
		nextAntCreatedTick += antIncreaseRate;
		uint numberOfAntsToCreate = foodCount / foodPerAnt;
		if (numberOfAntsToCreate == 0) ++numberOfAntsToCreate;
		
		for (uint i = 0; i < numberOfAntsToCreate; ++i)
		{
			
		}
	}
}

void AntHome::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}