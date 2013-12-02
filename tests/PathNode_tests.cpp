#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/nav/PathNode.hpp"
#include "../sim/nav/Node.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace cdc;
using namespace std;

namespace tests
{
	TEST_CLASS(PathNode_tests)
	{
	public:
		
		TEST_METHOD(PathNode_create)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			PathNode pathNode(node, 100, 100);
		}

		TEST_METHOD(PathNode_operatorEqual)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			PathNode pathNode(node, 100, 100);

			Node node2(GridLocation(3, 1), 100, 200);
			PathNode pathNode2(node2, 100, 100);

			Assert::IsTrue(pathNode == node);
			Assert::IsFalse(pathNode == pathNode2);
		}

		TEST_METHOD(PathNode_operatorEqualNode)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			PathNode pathNode(node, 100, 100);

			Node node2(GridLocation(5, 2), 100, 200);

			Assert::IsTrue(pathNode == node);
			Assert::IsFalse(pathNode == node2);
		}

		TEST_METHOD(PathNode_getCost)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			PathNode pathNode(node, 100, 100);

			Assert::AreEqual(pathNode.getCost(), 200.f);
		}

		TEST_METHOD(PathNode_getNode)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			PathNode pathNode(node, 100, 100);

			Assert::IsTrue(pathNode.getNode() == node);
		}

		TEST_METHOD(PathNode_getEdgeList)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);

			auto edge = make_shared<Edge>(startNode, endNode, 5.f);
			startNode.addEdge(edge);

			PathNode pathNode(startNode, 100.f, 100.f);

			Assert::AreEqual(pathNode.getEdgeList().size(), 1u);
		}
	};
}