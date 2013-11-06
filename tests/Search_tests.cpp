#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/nav/Search.hpp"

#include <iostream>
#include <iomanip>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;
using namespace std;

vector<Node> createNavGraph1();

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

		TEST_METHOD(Search_manhattanHeuristic_1)
		{
			Node node1(GridLocation(5, 1), 10, 20);
			Node node2(GridLocation(6, 1), 10, 20);

			auto distance = cdc::Search::manhattanHeuristic(node1, node2);
			Assert::AreEqual(1u, distance);
		}

		TEST_METHOD(Search_manhattanHeuristic_2)
		{
			Node node1(GridLocation(5, 1), 10, 20);
			Node node2(GridLocation(6, 1), 10, 20);

			auto distance = cdc::Search::manhattanHeuristic(node2, node1);
			Assert::AreEqual(1u, distance);
		}

		TEST_METHOD(Search_manhattanHeuristic_3)
		{
			Node node1(GridLocation(3, 1), 10, 20);
			Node node2(GridLocation(6, 3), 10, 20);

			auto distance = cdc::Search::manhattanHeuristic(node1, node2);
			Assert::AreEqual(5u, distance);
		}

		TEST_METHOD(Search_manhattanHeuristic_4)
		{
			Node node1(GridLocation(3, 1), 10, 20);
			Node node2(GridLocation(3, 3), 10, 20);

			auto distance = cdc::Search::manhattanHeuristic(node1, node2);
			Assert::AreEqual(2u, distance);
		}

		TEST_METHOD(Search_AStarStraightLine_1)
		{
			auto navGraph = createNavGraph1();

			auto path = cdc::Search::aStar(navGraph[0], navGraph[7], navGraph,
					cdc::Search::straightLineHeuristic);
			
			Node* node = nullptr;
			while (!path.empty())
			{
				node = path.front();
				path.pop_front();
			}

			Assert::IsTrue(*node == navGraph[7]);
		}

		TEST_METHOD(Search_AStarStraightLine_2)
		{
			auto navGraph = createNavGraph1();

			auto path = cdc::Search::aStar(navGraph[0], navGraph[11], navGraph,
					cdc::Search::straightLineHeuristic);
			
			Node* node = nullptr;
			while (!path.empty())
			{
				node = path.front();
				path.pop_front();
			}

			Assert::IsTrue(*node == navGraph[11]);
		}

		TEST_METHOD(Search_AStarStraightLine_3)
		{
			auto navGraph = createNavGraph1();

			auto path = cdc::Search::aStar(navGraph[9], navGraph[3], navGraph,
					cdc::Search::straightLineHeuristic);
			
			Node* node = nullptr;
			while (!path.empty())
			{
				node = path.front();
				path.pop_front();
			}

			Assert::IsTrue(*node == navGraph[3]);
		}

		TEST_METHOD(Search_AStarManhattan_1)
		{
			auto navGraph = createNavGraph1();

			auto path = cdc::Search::aStar(navGraph[0], navGraph[7], navGraph,
					cdc::Search::manhattanHeuristic);
			
			Node* node = nullptr;
			while (!path.empty())
			{
				node = path.front();
				path.pop_front();
			}

			Assert::IsTrue(*node == navGraph[7]);
		}

		TEST_METHOD(Search_AStarManhattan_2)
		{
			auto navGraph = createNavGraph1();

			auto path = cdc::Search::aStar(navGraph[0], navGraph[11], navGraph,
					cdc::Search::manhattanHeuristic);
			
			Node* node = nullptr;
			while (!path.empty())
			{
				node = path.front();
				path.pop_front();
			}

			Assert::IsTrue(*node == navGraph[11]);
		}

		TEST_METHOD(Search_AStarManhattan_3)
		{
			auto navGraph = createNavGraph1();

			auto path = cdc::Search::aStar(navGraph[9], navGraph[3], navGraph,
					cdc::Search::manhattanHeuristic);
			
			Node* node = nullptr;
			while (!path.empty())
			{
				node = path.front();
				path.pop_front();
			}

			Assert::IsTrue(*node == navGraph[3]);
		}

		vector<Node> createNavGraph1()
		{
			vector<Node> navGraph;
			navGraph.push_back(Node(GridLocation(0, 0), 10, 20));	// 0
			navGraph.push_back(Node(GridLocation(0, 1), 10, 20));	// 1
			navGraph.push_back(Node(GridLocation(0, 2), 10, 20));	// 2
			navGraph.push_back(Node(GridLocation(0, 3), 10, 20));	// 3
			navGraph.push_back(Node(GridLocation(1, 0), 10, 20));	// 4
			navGraph.push_back(Node(GridLocation(1, 1), 10, 20));	// 5
			navGraph.push_back(Node(GridLocation(1, 2), 10, 20));	// 6
			navGraph.push_back(Node(GridLocation(1, 3), 10, 20));	// 7
			navGraph.push_back(Node(GridLocation(2, 0), 10, 20));	// 8
			navGraph.push_back(Node(GridLocation(2, 1), 10, 20));	// 9
			navGraph.push_back(Node(GridLocation(2, 2), 10, 20));	// 10
			navGraph.push_back(Node(GridLocation(2, 3), 10, 20));	// 11

			auto edge_00_01 = make_shared<Edge>(navGraph[0], navGraph[1], 1);
			auto edge_00_10 = make_shared<Edge>(navGraph[0], navGraph[4], 1);
			navGraph[0].addEdge(edge_00_01).addEdge(edge_00_10);
			
			auto edge_01_02 = make_shared<Edge>(navGraph[1], navGraph[2], 1);
			auto edge_01_11 = make_shared<Edge>(navGraph[1], navGraph[5], 1);
			navGraph[1].addEdge(edge_01_02).addEdge(edge_01_11);

			auto edge_02_03 = make_shared<Edge>(navGraph[2], navGraph[3], 1);
			auto edge_02_12 = make_shared<Edge>(navGraph[2], navGraph[6], 1);
			navGraph[2].addEdge(edge_02_03).addEdge(edge_02_12);

			auto edge_03_13 = make_shared<Edge>(navGraph[3], navGraph[7], 1);
			navGraph[3].addEdge(edge_03_13);

			auto edge_10_11 = make_shared<Edge>(navGraph[4], navGraph[5], 1);
			auto edge_10_20 = make_shared<Edge>(navGraph[4], navGraph[8], 1);
			navGraph[4].addEdge(edge_10_11).addEdge(edge_10_20);

			auto edge_11_12 = make_shared<Edge>(navGraph[5], navGraph[6], 1);
			auto edge_11_21 = make_shared<Edge>(navGraph[5], navGraph[9], 1);
			navGraph[5].addEdge(edge_11_12).addEdge(edge_11_21);

			auto edge_12_13 = make_shared<Edge>(navGraph[6], navGraph[7], 1);
			auto edge_12_22 = make_shared<Edge>(navGraph[6], navGraph[10], 1);
			navGraph[6].addEdge(edge_12_13).addEdge(edge_12_22);

			auto edge_13_23 = make_shared<Edge>(navGraph[7], navGraph[11], 1);
			navGraph[7].addEdge(edge_13_23);

			auto edge_20_21 = make_shared<Edge>(navGraph[8], navGraph[9], 1);
			navGraph[8].addEdge(edge_20_21);

			auto edge_21_22 = make_shared<Edge>(navGraph[9], navGraph[10], 1);
			navGraph[9].addEdge(edge_21_22);

			auto edge_22_23 = make_shared<Edge>(navGraph[10], navGraph[11], 1);
			navGraph[10].addEdge(edge_22_23);

			return navGraph;
		}
	};
}