#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/nav/Edge.hpp"
#include "../sim/nav/Node.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(Edge_tests)
	{
	public:
		
		TEST_METHOD(Edge_create)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);

			Edge edge(startNode, endNode, 5);
		}

		TEST_METHOD(Edge_set)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);

			Edge edge(startNode);
			edge.set(endNode, 10);
		}

		TEST_METHOD(Edge_getStartNode)
		{
			Node startNode(GridLocation(1, 2), 20, 30);

			Edge edge(startNode);
			Assert::IsTrue(edge.getStartNode() == &startNode);
		}

		TEST_METHOD(Edge_getEndNode)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);

			Edge edge(startNode, endNode, 10);
			Assert::IsTrue(edge.getEndNode() == &endNode);
		}

		TEST_METHOD(Edge_getCost)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);

			Edge edge(startNode, endNode, 5);
			Assert::AreEqual(edge.getCost(), 5u);
			Assert::AreNotEqual(edge.getCost(), 10u);
		}

		TEST_METHOD(Edge_isEmpty)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);

			Edge edge(startNode, endNode, 5);
			Assert::IsFalse(edge.isEmpty());
		}
	};
}