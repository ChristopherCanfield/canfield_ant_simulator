#pragma once

// Christopher D. Canfield
// October 2013
// Ants.hpp

#include "Agent.hpp"
#include "../../gui/Button.hpp"
#include "../knowledge/AntKnowledgeBase.hpp"
#include "../knowledge/Percept.hpp"
#include "../knowledge/AntPercept.hpp"

#include <SFML/Graphics.hpp>


namespace cdc
{
	// An ant intelligent agent.
	class Ant :
			public Agent,
			public Button
	{
	public:
		Ant(GuiEventManager& manager);
		Ant(Ant&& other);
		virtual ~Ant();

		virtual void update(const Percept& percept) override;

		virtual void onDirectGuiEvent(const sf::Event& e) override;

	private:
		Ant(const Ant&);
		Ant& operator=(const Ant& other);

		static sf::Texture* texture;
		static bool wasTextureLoaded;

		AntKnowledgeBase kb;
	};
}

