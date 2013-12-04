#pragma once

// Christopher D. Canfield
// October 2013
// ViewManager.hpp

#include "GuiEventObserver.hpp"
#include "GuiEventManager.hpp"
#include "../util/Typedefs.hpp"

#include <SFML/Graphics.hpp>

#include <Poco/UUID.h>

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

		virtual Poco::UUID getObserverId() const override;

		void setWindow(sf::RenderWindow& window);
		sf::View& getSimView();
		sf::View& getUiView();

		void setViewParameters(float xMovement, float yMovement, float zoom);

	private:
		void moveMainView(const sf::Event& e);

		Poco::UUID id;

		uint worldWidth;
		uint worldHeight;

		sf::View simView;
		sf::View uiView;
		sf::RenderWindow* window;
	};
}
