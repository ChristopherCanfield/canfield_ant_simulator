#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sim/goal/AntMoveToNode.hpp"
#include "../sim/nav/Node.hpp"
#include "../sim/worldobject/AntHome.hpp"
#include "../sim/nav/NavGraphHelper.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;
using namespace std;

namespace tests
{
	TEST_CLASS(AntMoveToLocation_tests)
	{
	public:
		
		TEST_METHOD(AntMoveToNode_create)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			vector<Node> vec;
			NavGraphHelper graph(vec);
			Ant ant(manager, home, graph);

			AntMoveToNode goal(ant, node);
		}

		TEST_METHOD(AntMoveToNode_update)
		{
			// TODO: implement this.
			Assert::IsTrue(false);
		}

		TEST_METHOD(AntMoveToNode_reset)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			vector<Node> vec;
			NavGraphHelper graph(vec);
			Ant ant(manager, home, graph);

			AntMoveToNode goal(ant, node);

			Node node2(location, 100, 200);
			goal.reset(ant, node2);
		}
	};
}