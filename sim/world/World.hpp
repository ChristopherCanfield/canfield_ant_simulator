#pragma once

#include "World.hpp"
#include "../nav/Node.hpp"
#include "../agent/Ant.hpp"
#include "../agent/Spider.hpp"
#include "../worldobject/AntFood.hpp"
#include "../worldobject/AntFoodPile.hpp"
#include "../worldobject/AntHome.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

// Christopher D. Canfield
// October 2013
// World.hpp


namespace cdc
{
	class GuiEventManager;

	// Interface for world creators. World creators define the simulation world,
	// including the nav graph and initial locations of entities in the world.
	class World
	{
	public:
		virtual ~World();

		// Creates the world.
		virtual void create(GuiEventManager& eventManager) = 0;

		GuiEventManager& getGuiEventManager();
		std::vector<Node>& getNavGraph();
		std::vector<std::unique_ptr<Ant>>& getAnts();
		std::vector<Spider>& getSpiders();
		std::vector<sf::Sprite>& getObstructions();
		std::vector<AntFood>& getAntFood();
		std::vector<std::unique_ptr<AntFoodPile>>& getAntFoodPiles();
		std::vector<std::unique_ptr<AntHome>>& getAntHills();

	protected:
		GuiEventManager* eventManager;

		std::vector<Node> navGraph;

		std::vector<std::unique_ptr<Ant>> ants;
		std::vector<Spider> spiders;

		std::vector<sf::Sprite> obstructions;

		std::vector<AntFood> antFood;
		std::vector<std::unique_ptr<AntFoodPile>> antFoodPiles;

		std::vector<std::unique_ptr<AntHome>> antHills;
	};
}