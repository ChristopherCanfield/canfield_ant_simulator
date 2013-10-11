#include "stdafx.h"
#include "CppUnitTest.h"

#include "../util/nav/Edge.hpp"
#include "../util/nav/GridNode.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(Edge_tests)
	{
	public:
		
		TEST_METHOD(Edge_create)
		{
			GridNode node(GridLocation(1, 2), 20, 30);
			Edge edge(node, 5);
			Edge edge2;
		}

		TEST_METHOD(Edge_set)
		{
			Edge edge;
			GridNode node(GridLocation(1, 2), 20, 30);
			edge.set(node, 10);
		}

		TEST_METHOD(Edge_getCost)
		{
			GridNode node(GridLocation(1, 2), 20, 30);
			Edge edge(node, 5);
			Assert::AreEqual(edge.getCost(), 5u);
			Assert::AreNotEqual(edge.getCost(), 10u);
		}

		/*TEST_METHOD(Edge_getNode)
		{
			GridNode node(GridLocation(1, 2), 20, 30);
			Edge edge(node, 5);
			Assert::AreSame(*edge.getNode(), node);
		}*/

		TEST_METHOD(Edge_isEmpty)
		{
			GridNode node(GridLocation(1, 2), 20, 30);
			Edge edge(node, 5);
			Assert::IsFalse(edge.isEmpty());
		}
	};
}