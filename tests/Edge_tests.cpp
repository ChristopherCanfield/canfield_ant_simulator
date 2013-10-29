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

		TEST_METHOD(Edge_getNode1)
		{
			Node startNode(GridLocation(1, 2), 20, 30);

			Edge edge(startNode);
			Assert::IsTrue(edge.getNode1() == &startNode);
		}

		TEST_METHOD(Edge_getNode2)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);

			Edge edge(startNode, endNode, 10);
			Assert::IsTrue(edge.getNode2() == &endNode);
		}

		TEST_METHOD(Edge_getCost)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);

			Edge edge(startNode, endNode, 5);
			Assert::AreEqual(edge.getCost(), 5u);
			Assert::AreNotEqual(edge.getCost(), 10u);
		}

		TEST_METHOD(Edge_getPheromone)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);

			Edge edge(startNode, endNode, 5);
			Assert::AreEqual(0u, edge.getPheromone());
		}

		TEST_METHOD(Edge_increasePheromone)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);

			Edge edge(startNode, endNode, 5);
			edge.increasePheromone();
			Assert::AreEqual(1u, edge.getPheromone());
		}

		TEST_METHOD(Edge_decreasePheromone)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);

			Edge edge(startNode, endNode, 5);
			edge.decreasePheromone();
			Assert::AreEqual(0u, edge.getPheromone());

			edge.increasePheromone();
			edge.increasePheromone();
			edge.decreasePheromone();
			Assert::AreEqual(1u, edge.getPheromone());
		}
	};
}