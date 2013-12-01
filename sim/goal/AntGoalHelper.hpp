#pragma once


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
	};
}
