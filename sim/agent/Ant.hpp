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
#include <SFML/System/Vector2.hpp>

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
		Ant(GuiEventManager& manager, AntHome& home, NavGraphHelper& navGraphHelper, const Node& startNode);
		Ant(Ant&& other);
		virtual ~Ant();

		virtual void update(uint ticks, const Percept& percept) override;

		// Returns the last known Node to contain food, or nullptr if no Node
		// is known to have food.
		Node* getLastKnownFoodPosition() const;

		// Returns the ant's hunger level, from 0 (full/satiated) to 100 (starving).
		uint getHunger() const;

		// Returns the ant's home.
		AntHome& getHome() const;

		// Returns the last node that this ant passed.
		Node& getNode() const;

		// Returns true if the ant is dead, or false if alive.
		bool isDead() const;
		// Kill's the ant (sets isDead to true).
		void kill();

		// GUI event handlers.
		virtual void onDirectGuiEvent(const sf::Event& e) override;
		virtual void onGuiEvent(const sf::Event& e) override;

		// The AntGoal classes are friends, because they control the ant and 
		// need access to details that should not be made public.
		friend class AntEat;
		friend class AntForage;
		friend class AntGoHome;
		friend class AntExplore;
		friend class AntMoveToNode;
		friend class AntFindFood;
		friend class AntFollowPath;

	protected:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

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

			sf::Vector2f movementVector;
			// The movement speed, per simulation tick.
			const float movementSpeed;

			bool isDead;
		private:
			AntStats& operator=(const AntStats& rhs);
		};
		AntStats stats;

		// The ant's knowledge base.
		struct AntKnowledgeBase
		{
			AntKnowledgeBase(AntHome& home, NavGraphHelper& navGraphHelper);
			// TODO: change this to use a circular buffer (look into boost version).
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

		// Increases the ant's hunger when appropriate.
		void processHunger(uint ticks, AntStats& stats);

	private:
		Ant(const Ant&);
		Ant& operator=(const Ant& other);

		// Called when the ant has died.
		void onDeath();

		// TODO: remove this if the initial AntMoveToNode goal works properly.
		// Moves the ant to the specified node.
		//void moveToNode(const Node& node);

		// Ant texture; used by all ants.
		static sf::Texture* texture;
		static bool wasTextureLoaded;
		sf::Sprite deadAntSprite;

		// Whether the ant is currently selected. This can be used to get debug
		// or state information.
		bool isSelected;

		// Gets a new goal for the ant.
		std::unique_ptr<AntGoal> getNewGoal(AntStats& stats);
	};
}

