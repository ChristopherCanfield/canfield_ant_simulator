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
		ViewManager(GuiEventManager& eventManager, 
				uint worldWidth, uint worldHeight, 
				uint simViewWidth, uint simViewHeight,
				uint uiViewWidth, uint uiViewHeight);
		~ViewManager();

		virtual void onGuiEvent(const sf::Event& e) override;

		void setWindow(sf::RenderWindow* window);
		const sf::View& getSimView() const;
		const sf::View& getUiView() const;

	private:
		void moveMainView(const sf::Event& e);

		uint worldWidth;
		uint worldHeight;

		sf::View simView;
		sf::View uiView;
		sf::RenderWindow* window;
	};
}
