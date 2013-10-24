#pragma once

#include "Agent.hpp"
#include "../../gui/Button.hpp"
#include "../knowledge/AntKnowledgeBase.hpp"
#include "../knowledge/Percept.hpp"
#include "../knowledge/AntPercept.hpp"


namespace cdc
{
	// An ant intelligent agent.
	class Ant :
			public Agent,
			public Button
	{
	public:
		Ant(GuiEventManager& manager);
		virtual ~Ant();

		virtual void update(const Percept& percept) override;

		virtual void onDirectGuiEvent(const sf::Event& e) override;

	private:
		AntKnowledgeBase kb;
	};
}

