#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/nav/Node.hpp"
#include "../sim/nav/GridLocation.hpp"
#include "../sim/nav/Edge.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

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
			Node node(location, 100, 200);

			Edge edge;
			node.addEdge(edge);
		}

		TEST_METHOD(Node_addEdge2)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			Edge edge;
			node.addEdge(edge, false);
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
			Node node(location, 100, 200);

			Edge edge;
			node.addEdge(edge);

			auto edge2 = node.getEdge(0);
		}

		TEST_METHOD(Node_getPixelX)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			auto pixelX = node.getPixelX();
		}

		TEST_METHOD(Node_getPixelY)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			auto pixelY = node.getPixelY();
		}

		TEST_METHOD(Node_getRow)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			auto row = node.getRow();
		}

		TEST_METHOD(Node_getColumn)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			auto column = node.getColumn();
		}
	};
}