#pragma once

// Christopher D. Canfield
// October 2013
// Ant.hpp

#include "Agent.hpp"
#include "../../gui/Button.hpp"
#include "../util/Typedefs.hpp"
#include "../util/Random.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include <boost/circular_buffer.hpp>

#include <memory>


namespace cdc
{
	class Node;
	class NavGraphHelper;
	class AntHome;
	class AntGoal;
	class Percept;

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

		// Pops the last known Node that had food on it, or nullptr if no Node
		// is known to have food.
		const Node* popLastKnownFoodPosition();

		// Returns the ant's hunger level, from 0 (full/satiated) to 100 (starving).
		uint getHunger() const;

		// Returns the ant's home.
		AntHome& getHome() const;

		// Returns the last node that this ant passed.
		Node& getNode() const;

		// Returns true if the ant is dead, or false if alive.
		bool isDead() const;
		// Sets isDead to true).
		void kill();

		// Returns true if the ant is selected.
		bool isSelected() const;

		// Returns true if the ant is holding food.
		bool isHoldingFood() const;

		// GUI event handlers.
		virtual void onDirectGuiEvent(const sf::Event& e) override;
		virtual void onGuiEvent(const sf::Event& e) override;

		// Draws the ant's path to its target.
		void drawPath(sf::RenderTarget &target, sf::RenderStates states) const;

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

		// Returns true if the ant is hungry.
		bool isHungry() const;

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
			uint nextHungerIncrease;

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
			// Circular buffer (stack) that remembers up to 4 food piles that the 
			// ant has found.
			boost::circular_buffer<const Node*> lastKnownFoodPosition;
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

		void setAntWithFoodSpritePosition(float x, float y, float rotation);

	private:
		Ant(const Ant&);
		Ant& operator=(const Ant& other);

		// Called when the ant has died.
		void onDeath();

		// Called when the ant picks up food.
		void onPickUpFood();

		// Sets the position of the ant to the position of the specified node.
		void setPositionToNode(const Node& node);

		// Ant texture; used by all ants.
		static sf::Texture* texture;
		sf::Sprite selectedAntSprite;
		sf::Sprite deadAntSprite;
		static sf::Texture* textureWithFood;
		sf::Sprite antWithFoodSprite;

		void Ant::updateSpritePositions();

		// Whether the ant is currently selected. This can be used to get debug
		// or state information.
		bool selected;
		sf::Clock selectedTimer;

		// Gets a new goal for the ant.
		std::unique_ptr<AntGoal> getNewGoal();
	};
}

