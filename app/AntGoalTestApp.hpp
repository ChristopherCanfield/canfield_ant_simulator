#pragma once

#include "App.hpp"
#include "../gui/ViewManager.hpp"
#include "../sim/nav/NavGraphHelper.hpp"
#include "../sim/Simulator.hpp"

#include <SFML/Window.hpp>

#include <memory>
#include <vector>

// Christopher D. Canfield
// November 2013
// AntGoalTestApp.hpp


namespace cdc
{
	class Node;
	class AntHome;
	class AntFoodPile;
	class AntGoalTester;

	class AntGoalTestApp :
		public App
	{
	public:
		AntGoalTestApp();
		virtual ~AntGoalTestApp();

		virtual void setup() override;
		virtual bool run() override;
		virtual void teardown() override;

	private:
		std::unique_ptr<AntGoalTester> ant;

		GuiEventManager eventManager;

		AntFoodPile* foodPile;
		AntHome* antHome;

		std::vector<std::unique_ptr<Node>> navGraph;
		NavGraphHelper navGraphHelper;

		std::unique_ptr<sf::RenderWindow> window;

		ViewManager viewManager;
	};
}
