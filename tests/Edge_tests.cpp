#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/nav/Edge.hpp"
#include "../sim/nav/Node.hpp"
#include "../sim/nav/PathNode.hpp"

#include <memory>

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

			Edge edge(startNode, endNode, 5.f);
			Assert::AreEqual(edge.getCost(), 5.f);
			Assert::AreNotEqual(edge.getCost(), 10.f);
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

		TEST_METHOD(Edge_getOppositeNode)
		{
			using namespace std;

			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(2, 1), 20, 30);

			auto edge = make_shared<Edge>(startNode, endNode, 5.f);
			Node* oppNode = edge->getOppositeNode(endNode);

			Assert::AreEqual(startNode.getRow(), oppNode->getRow());
			Assert::AreNotEqual(endNode.getRow(), oppNode->getRow());
			Assert::AreEqual(startNode.getColumn(), oppNode->getColumn());
			Assert::AreNotEqual(endNode.getColumn(), oppNode->getColumn());

			Assert::IsTrue(startNode == *oppNode);
			Assert::IsFalse(endNode == *oppNode);
		}

		TEST_METHOD(Edge_getOppositeNode2)
		{
			using namespace std;

			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(2, 1), 20, 30);

			auto edge = make_shared<Edge>(startNode, endNode, 5);
			Node* oppNode = edge->getOppositeNode(startNode);

			Assert::AreNotEqual(startNode.getRow(), oppNode->getRow());
			Assert::AreEqual(endNode.getRow(), oppNode->getRow());
			Assert::AreNotEqual(startNode.getColumn(), oppNode->getColumn());
			Assert::AreEqual(endNode.getColumn(), oppNode->getColumn());

			Assert::IsFalse(startNode == *oppNode);
			Assert::IsTrue(endNode == *oppNode);
		}

		TEST_METHOD(Edge_getOppositeNode_PathNode)
		{
			using namespace std;

			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(2, 1), 20, 30);

			auto edge = make_shared<Edge>(startNode, endNode, 5);
			PathNode pathNode(startNode, 10);
			Node* oppNode = edge->getOppositeNode(pathNode);

			Assert::AreNotEqual(startNode.getRow(), oppNode->getRow());
			Assert::AreEqual(endNode.getRow(), oppNode->getRow());
			Assert::AreNotEqual(startNode.getColumn(), oppNode->getColumn());
			Assert::AreEqual(endNode.getColumn(), oppNode->getColumn());

			Assert::IsFalse(startNode == *oppNode);
			Assert::IsTrue(endNode == *oppNode);
		}
	};
}