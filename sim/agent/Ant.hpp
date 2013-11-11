#pragma once

// Christopher D. Canfield
// October 2013
// Ant.hpp

#include "Agent.hpp"
#include "../../gui/Button.hpp"
#include "../knowledge/Percept.hpp"
#include "../knowledge/AntPercept.hpp"
#include "../util/Typedefs.hpp"
#include "../util/Random.hpp"

#include <SFML/Graphics.hpp>

#include <memory>


namespace cdc
{
	class Node;
	class NavGraphHelper;
	class AntHome;
	class AntGoal;

	// An ant intelligent agent.
	class Ant :
			public Agent,
			public Button
	{
	public:
		Ant(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper);
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

		// Returns the last node that this ant passed.
		Node* getNode() const;

		// Returns true if the ant is dead, or false if alive.
		bool isDead() const;
		// Kill's the ant (sets isDead to true).
		void kill();

		virtual void onDirectGuiEvent(const sf::Event& e) override;

		// The AntGoal classes are friends, because they control the ant and 
		// need access to details that should not be made public.
		friend class AntEat;
		friend class AntForage;
		friend class AntGoHome;

	private:
		Ant(const Ant&);
		Ant& operator=(const Ant& other);

		// The ant's non-knowledge info.
		struct AntStats
		{
			AntStats();

			// The ant's hunger level, from 0 to 100.
			uint hunger;

			// The number of simulation ticks that pass before the ant's hunger
			// level increases. The default ticks per second rate is 30.
			const uint hungerIncreaseRate;

			// The next tick that will cause the ant's hunger to increase.
			long nextHungerIncrease;

			// The max hunger that the ant can have. If this is exceeded, the ant dies.
			const uint maxHunger;

			bool isHoldingFood;

			bool isDead;
		private:
			AntStats& operator=(const AntStats& rhs);
		};
		AntStats stats;

		// The ant's knowledge base.
		struct AntKnowledgeBase
		{
			AntKnowledgeBase(AntHome& home, NavGraphHelper& navGraphHelper);
			Node* lastKnownFoodPosition;
			AntHome& home;
			Node* lastNodePassed;
			NavGraphHelper& navGraphHelper;
		private:
			AntKnowledgeBase& operator=(const AntKnowledgeBase& rhs);
		};
		AntKnowledgeBase kb;

		// The ant's current goal.
		std::unique_ptr<AntGoal> goal;

		Random random;

		// Ant texture; used by all ants.
		static sf::Texture* texture;
		static bool wasTextureLoaded;

		// Increases the ant's hunger when appropriate.
		void processHunger(long ticks, AntStats& stats);

		// Gets a new goal for the ant.
		std::unique_ptr<AntGoal> getNewGoal(AntStats& stats);
	};
}

