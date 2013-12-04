#pragma once

#include <SFML/Graphics.hpp>

#include <deque>

// Christopher D. Canfield
// December 2013
// AntGoalHelper.hpp


namespace cdc
{
	class Node;
	class NavGraphHelper;

	class AntGoalHelper
	{
	public:
		static Node& getNewTarget(NavGraphHelper& navGraphHelper, const Node& nodeToExclude);
		static void drawPath(sf::RenderTarget& target, sf::RenderStates states, const std::deque<Node*>& path, const Node& lastNodePassed);
	};
}
