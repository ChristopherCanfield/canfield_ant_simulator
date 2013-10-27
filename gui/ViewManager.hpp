#pragma once

// Christopher D. Canfield
// October 2013
// ViewManager.hpp

#include "GuiEventObserver.hpp"
#include "GuiEventManager.hpp"
#include "../util/Typedefs.hpp"

#include <SFML/Graphics.hpp>

namespace cdc
{

	class ViewManager :
			public GuiEventObserver
	{
	public:
		ViewManager(GuiEventManager& eventManager, uint worldWidth, uint worldHeight, uint viewWidth, uint viewHeight);
		~ViewManager();

		virtual void onGuiEvent(const sf::Event& e) override;

		void setWindow(sf::RenderWindow* window);
		const sf::View& getView() const;

	private:
		uint worldWidth;
		uint worldHeight;

		sf::View view;
		sf::RenderWindow* window;
	};
}
