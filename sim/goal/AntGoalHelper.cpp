#include "AntGoalHelper.hpp"
#include "../nav/Node.hpp"
#include "../nav/NavGraphHelper.hpp"
#include "../../util/Random.hpp"
#include "../../util/Typedefs.hpp"

// Christopher D. Canfield
// December 2013
// AntGoalHelper.hpp

using namespace cdc;


Node& AntGoalHelper::getNewTarget(NavGraphHelper& navGraphHelper)
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
	}

	return *navGraphHelper.getNode(GridLocation(row, column));
}