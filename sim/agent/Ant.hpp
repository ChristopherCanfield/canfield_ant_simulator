#pragma once

// Christopher D. Canfield
// October 2013
// Ants.hpp

#include "Agent.hpp"
#include "../../gui/Button.hpp"
#include "../knowledge/Percept.hpp"
#include "../knowledge/AntPercept.hpp"
#include "../util/Typedefs.hpp"

#include <SFML/Graphics.hpp>


namespace cdc
{
	class Node;
	class AntHome;

	// An ant intelligent agent.
	class Ant :
			public Agent,
			public Button
	{
	public:
		explicit Ant(GuiEventManager& manager, AntHome& home);
		Ant(Ant&& other);
		virtual ~Ant();

		virtual void update(long ticks, const Percept& percept) override;

		// Returns the last known Node to contain food, or nullptr if no Node
		// is known to have food.
		Node* getLastKnownFoodPosition() const;

		// Returns the ant's hunger level, from 0 (full/satiated) to 100 (starving).
		uint getHunger() const;

		// Returns the ant's home.
		AntHome& getHome() const;

		virtual void onDirectGuiEvent(const sf::Event& e) override;

		friend class AntForage;

	private:
		Ant(const Ant&);
		Ant& operator=(const Ant& other);

		struct AntKnowledgeBase
		{
			AntKnowledgeBase(AntHome& home);

			Node* lastKnownFoodPosition;
			AntHome& home;
			uint hunger;

			// The number of simulation ticks that pass before the ant's hunger
			// level increases.
			const uint hungerIncreaseRate;

		private:
			AntKnowledgeBase& operator=(const AntKnowledgeBase& rhs);
		};

		AntKnowledgeBase kb;

		static sf::Texture* texture;
		static bool wasTextureLoaded;
	};
}

