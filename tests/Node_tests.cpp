#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/nav/Node.hpp"
#include "../sim/nav/GridLocation.hpp"
#include "../sim/nav/Edge.hpp"

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
	};
}