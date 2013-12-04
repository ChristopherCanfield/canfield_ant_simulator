#include "AntGoalHelper.hpp"
#include "../nav/Node.hpp"
#include "../nav/NavGraphHelper.hpp"
#include "../../util/Random.hpp"
#include "../../util/Typedefs.hpp"

// Christopher D. Canfield
// December 2013
// AntGoalHelper.hpp

using namespace cdc;


Node& AntGoalHelper::getNewTarget(NavGraphHelper& navGraphHelper, const Node& nodeToExclude)
{
	const int maxRow = static_cast<int>(navGraphHelper.getMaxRow());
	const int maxColumn = static_cast<int>(navGraphHelper.getMaxColumn());

	uint row = 0;
	uint column = 0;
	Random rand;
	bool validNodeLocation = false;

	while (!validNodeLocation)
	{
		row = rand.getInteger(0, maxRow);
		column = rand.getInteger(0, maxColumn);

		validNodeLocation = navGraphHelper.isValid(GridLocation(row, column));
		if (row == nodeToExclude.getRow() && column == nodeToExclude.getColumn())
		{
			validNodeLocation = false;
		}
	}

	return *navGraphHelper.getNode(GridLocation(row, column));
}

void AntGoalHelper::drawPath(sf::RenderTarget& target, sf::RenderStates states, const std::deque<Node*>& path, const Node& lastNodePassed)
{
	if (!path.empty())
	{
		const Node* previousNode = &lastNodePassed;
		for (auto node : path)
		{
			if (previousNode != nullptr)
			{
				for (auto& edge : node->getEdgeList())
				{
					if (edge->getOppositeNode(*node) == previousNode)
					{
						edge->draw(target, states, sf::Color::Black);
						break;
					}
				}
			}
			previousNode = node;
		}
	}
}