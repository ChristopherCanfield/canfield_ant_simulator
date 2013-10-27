#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/nav/Search.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(Search)
	{
	public:
		
		TEST_METHOD(Search_heuristicSearch_1)
		{
			Node node1(GridLocation(5, 1), 10, 20);
			Node node2(GridLocation(6, 1), 10, 20);

			auto searchHeuristic = cdc::Search::manhattanHeuristic(node1, node2);
			Assert::AreEqual(1u, searchHeuristic);
		}

		TEST_METHOD(Search_heuristicSearch_2)
		{
			Node node1(GridLocation(5, 1), 10, 20);
			Node node2(GridLocation(6, 1), 10, 20);

			auto searchHeuristic = cdc::Search::manhattanHeuristic(node2, node1);
			Assert::AreEqual(1u, searchHeuristic);
		}

		TEST_METHOD(Search_heuristicSearch_3)
		{
			Node node1(GridLocation(3, 1), 10, 20);
			Node node2(GridLocation(6, 3), 10, 20);

			auto searchHeuristic = cdc::Search::manhattanHeuristic(node1, node2);
			Assert::AreEqual(5u, searchHeuristic);
		}

		TEST_METHOD(Search_heuristicSearch_4)
		{
			Node node1(GridLocation(3, 1), 10, 20);
			Node node2(GridLocation(3, 3), 10, 20);

			auto searchHeuristic = cdc::Search::manhattanHeuristic(node1, node2);
			Assert::AreEqual(2u, searchHeuristic);
		}
	};
}