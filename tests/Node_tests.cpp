#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/nav/Node.hpp"
#include "../sim/nav/GridLocation.hpp"
#include "../sim/nav/Edge.hpp"

#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;
using namespace std;

namespace tests
{
	TEST_CLASS(Node_tests)
	{
	public:
		
		TEST_METHOD(Node_create)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
		}

		TEST_METHOD(Node_addEdge)
		{
			GridLocation location(5, 1);
			Node node1(location, 100, 200);
			Node node2(location, 100, 200);

			auto edge = make_shared<Edge>(node1, node2, 10);
			node1.addEdge(edge);
		}

		TEST_METHOD(Node_getEdgeList)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			auto list = node.getEdgeList();
		}

		TEST_METHOD(Node_getEdge)
		{
			GridLocation location(5, 1);
			Node node1(location, 100, 200);
			Node node2(location, 100, 200);

			auto edge = make_shared<Edge>(node1, node2, 10);
			node1.addEdge(edge);

			const auto edge2 = node1.getEdge(0);
			auto edge3 = node1.getEdgeList()[0];
			Assert::IsTrue(*edge3 == edge2);
			Assert::IsTrue(*edge == edge2);
		}

		TEST_METHOD(Edge_edgeExists1)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);

			auto edge = make_shared<Edge>(startNode, endNode, 10);
			startNode.addEdge(edge);
			Assert::IsTrue(startNode.edgeExists(edge));
		}

		TEST_METHOD(Edge_edgeExists2)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);
			Node otherNode(GridLocation(2, 2), 25, 35);

			auto edge = make_shared<Edge>(startNode, endNode, 10);
			startNode.addEdge(edge);
			auto edge2 = make_shared<Edge>(startNode, otherNode, 10);
			Assert::IsTrue(startNode.edgeExists(edge));
			Assert::IsTrue(startNode.edgeExists(edge2));
		}

		TEST_METHOD(Edge_edgeExists2)
		{
			Node startNode(GridLocation(1, 2), 20, 30);
			Node endNode(GridLocation(1, 2), 20, 30);
			Node otherNode(GridLocation(2, 2), 25, 35);

			auto edge = make_shared<Edge>(startNode, endNode, 10);
			startNode.addEdge(edge);
			auto edge2 = make_shared<Edge>(startNode, otherNode, 10);
			Assert::IsFalse(startNode.edgeExists(edge2));
		}

		TEST_METHOD(Node_getPixelX)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			auto pixelX = node.getPixelX();
			Assert::AreEqual(pixelX, 100);
		}

		TEST_METHOD(Node_getPixelY)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			auto pixelY = node.getPixelY();
			Assert::AreEqual(pixelY, 200);
		}

		TEST_METHOD(Node_getRow)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			auto row = node.getRow();
			Assert::AreEqual(row, 5u);
		}

		TEST_METHOD(Node_getColumn)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			auto column = node.getColumn();
			Assert::AreEqual(column, 1u);
		}

		TEST_METHOD(Node_getBoundingBox)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			sf::Rect<float> boundingBox(100.f - 3.f, 200.f - 3.f, 6.f, 6.f);
			Assert::IsTrue(boundingBox == node.getBoundingBox());
		}
	};
}