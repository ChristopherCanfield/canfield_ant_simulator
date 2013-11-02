#pragma once

// Christopher D. Canfield
// October 2013
// Spider.hpp

#include "Agent.hpp"
#include "../../gui/Button.hpp"
#include "../knowledge/SpiderKnowledgeBase.hpp"
#include "../knowledge/Percept.hpp"
#include "../knowledge/SpiderPercept.hpp"


namespace cdc
{
	// A spider intelligent agent.
	class Spider :
			public Agent,
			public Button
	{
	public:
		Spider(GuiEventManager& manager);
		virtual ~Spider();

		virtual void update(long ticks, const Percept& percept) override;

		virtual void onDirectGuiEvent(const sf::Event& e) override;

	private:
		static sf::Texture* texture;
		static bool wasTextureLoaded;

		SpiderKnowledgeBase kb;
	};
}
