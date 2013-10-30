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
		
		TEST_METHOD(Search_straightLineHeuristic_1)
		{
			Node node1(GridLocation(5, 1), 10, 20);
			Node node2(GridLocation(15, 21), 10, 20);

			auto heuristicDistance = cdc::Search::straightLineHeuristic(node1, node2);
			Assert::AreEqual(22u, heuristicDistance);
		}

		TEST_METHOD(Search_straightLineHeuristic_2)
		{
			Node node1(GridLocation(5, 1), 10, 10);
			Node node2(GridLocation(15, 11), 10, 10);

			auto heuristicDistance = cdc::Search::straightLineHeuristic(node1, node2);
			Assert::AreEqual(14u, heuristicDistance);
		}

		TEST_METHOD(Search_straightLineHeuristic_3)
		{
			Node node1(GridLocation(5, 1), 20, 20);
			Node node2(GridLocation(25, 21), 20, 20);

			auto heuristicDistance = cdc::Search::straightLineHeuristic(node1, node2);
			Assert::AreEqual(28u, heuristicDistance);
		}

		TEST_METHOD(Search_straightLineHeuristic_4)
		{
			Node node1(GridLocation(25, 21), 20, 20);
			Node node2(GridLocation(5, 1), 10, 10);

			auto heuristicDistance = cdc::Search::straightLineHeuristic(node1, node2);
			Assert::AreEqual(28u, heuristicDistance);
		}

		TEST_METHOD(Search_heuristicSearch_1)
		{
			Node node1(GridLocation(5, 1), 10, 20);
			Node node2(GridLocation(6, 1), 10, 20);

			auto distance = cdc::Search::manhattanHeuristic(node1, node2);
			Assert::AreEqual(1u, distance);
		}

		TEST_METHOD(Search_heuristicSearch_2)
		{
			Node node1(GridLocation(5, 1), 10, 20);
			Node node2(GridLocation(6, 1), 10, 20);

			auto distance = cdc::Search::manhattanHeuristic(node2, node1);
			Assert::AreEqual(1u, distance);
		}

		TEST_METHOD(Search_heuristicSearch_3)
		{
			Node node1(GridLocation(3, 1), 10, 20);
			Node node2(GridLocation(6, 3), 10, 20);

			auto distance = cdc::Search::manhattanHeuristic(node1, node2);
			Assert::AreEqual(5u, distance);
		}

		TEST_METHOD(Search_heuristicSearch_4)
		{
			Node node1(GridLocation(3, 1), 10, 20);
			Node node2(GridLocation(3, 3), 10, 20);

			auto distance = cdc::Search::manhattanHeuristic(node1, node2);
			Assert::AreEqual(2u, distance);
		}
	};
}