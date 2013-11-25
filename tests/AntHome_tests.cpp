#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sim/worldobject/AntHome.hpp"
#include "../sim/nav/Node.hpp"

#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;
using namespace std;

namespace tests
{
	TEST_CLASS(AntHome_tests)
	{
	public:
		
		TEST_METHOD(AntHome_create)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			vector<Node> navGraph;
			navGraph.push_back(node);

			AntHome home(node, navGraph);
		}

		TEST_METHOD(AntHome_getFoundCount)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			vector<Node> navGraph;
			navGraph.push_back(node);

			AntHome home(node, navGraph);
			Assert::AreEqual(0u, home.getFoodCount());
		}

		TEST_METHOD(AntHome_addFood)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			vector<Node> navGraph;
			navGraph.push_back(node);

			AntHome home(node, navGraph);
			home.addFood();
			Assert::AreEqual(1u, home.getFoodCount());
		}

		TEST_METHOD(AntHome_takeFood)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			vector<Node> navGraph;
			navGraph.push_back(node);

			AntHome home(node, navGraph);
			Assert::IsFalse(home.takeFood());
			Assert::AreEqual(0u, home.getFoodCount());

			home.addFood();
			home.addFood();
			Assert::IsTrue(home.takeFood());
			Assert::AreEqual(1u, home.getFoodCount());

			Assert::IsTrue(home.takeFood());
			Assert::AreEqual(0u, home.getFoodCount());

			Assert::IsFalse(home.takeFood());
			Assert::AreEqual(0u, home.getFoodCount());
		}
	};
}