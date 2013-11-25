#pragma once

#include "../util/Typedefs.hpp"
#include "../nav/NavGraphHelper.hpp"

#include <SFML/Graphics.hpp>

#include <vector>

// Christopher D. Canfield
// November 2013
// AntHome.hpp


namespace cdc
{
	class Node;

	// The home for a colony of Ants. Stores food and generates new ants.
	class AntHome :
		public sf::Drawable
	{
	public:
		AntHome(Node& node, std::vector<Node>& navGraph);
		~AntHome();

		// Returns a count of the food stored in the anthill.
		uint getFoodCount() const;

		// Takes one food. Returns true if successful, or false if not 
		// (i.e., there wasn't enough food).
		bool takeFood();

		// Adds one food to the anthill store.
		void addFood();

		// Returns the node that the anthill is attached to.
		Node& getNode() const;

		NavGraphHelper& getNavGraphHelper();

		void update(uint ticks);

	protected:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		AntHome& operator=(const AntHome& rhs);

		static sf::Texture* texture;
		static bool wasTextureLoaded;

		uint foodCount;
		Node& node;

		NavGraphHelper navGraphHelper;

		sf::Sprite sprite;
	};
}
