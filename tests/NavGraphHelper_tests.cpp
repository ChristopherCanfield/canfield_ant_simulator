#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sim/nav/NavGraphHelper.hpp"
#include "../sim/nav/Node.hpp"
#include "../sim/nav/Edge.hpp"
#include "../sim/nav/GridLocation.hpp"
#include "../util/make_unique.hpp"

#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;
using namespace std;

namespace tests
{
	TEST_CLASS(NavGraph_tests)
	{
	public:
		
		TEST_METHOD(NavGraphHelper_create)
		{
			GridLocation location(5, 1);
			auto node1 = make_unique<Node>(location, 100, 200);
			auto node2 = make_unique<Node>(location, 100, 300);
			
			auto edge = make_shared<Edge>(*node1.get(), *node2.get(), 10);
			node1->addEdge(edge);

			vector<unique_ptr<Node>> navGraph;

			navGraph.push_back(std::move(node1));
			navGraph.push_back(std::move(node2));

			NavGraphHelper graph(navGraph);
		}

		TEST_METHOD(NavGraphHelper_isValid)
		{
			auto node1 = make_unique<Node>(GridLocation(5, 1), 100, 200);
			auto node2 = make_unique<Node>(GridLocation(4, 4), 100, 300);
			
			auto edge = make_shared<Edge>(*node1.get(), *node2.get(), 10);
			node1->addEdge(edge);

			vector<unique_ptr<Node>> navGraph;

			navGraph.push_back(std::move(node1));
			navGraph.push_back(std::move(node2));

			NavGraphHelper graph(navGraph);
			Assert::IsTrue(graph.isValid(GridLocation(5, 1)));
			Assert::IsFalse(graph.isValid(GridLocation(1, 5)));
			Assert::IsFalse(graph.isValid(GridLocation(2, 2)));
			Assert::IsTrue(graph.isValid(GridLocation(4, 4)));
			Assert::IsFalse(graph.isValid(GridLocation(4, 3)));
		}

		TEST_METHOD(NavGraphHelper_getMaxRow)
		{
			auto node1 = make_unique<Node>(GridLocation(5, 1), 100, 200);
			auto node2 = make_unique<Node>(GridLocation(4, 4), 100, 300);
			
			auto edge = make_shared<Edge>(*node1.get(), *node2.get(), 10);
			node1->addEdge(edge);

			vector<unique_ptr<Node>> navGraph;

			navGraph.push_back(std::move(node1));
			navGraph.push_back(std::move(node2));

			NavGraphHelper graph(navGraph);
			Assert::AreEqual(5u, graph.getMaxRow());
		}

		TEST_METHOD(NavGraphHelper_getMaxColumn)
		{
			auto node1 = make_unique<Node>(GridLocation(5, 1), 100, 200);
			auto node2 = make_unique<Node>(GridLocation(4, 4), 100, 300);
			
			auto edge = make_shared<Edge>(*node1.get(), *node2.get(), 10);
			node1->addEdge(edge);

			vector<unique_ptr<Node>> navGraph;

			navGraph.push_back(std::move(node1));
			navGraph.push_back(std::move(node2));

			NavGraphHelper graph(navGraph);
			Assert::AreEqual(4u, graph.getMaxColumn());
		}

		TEST_METHOD(NavGraphHelper_getNode)
		{
			auto node1 = make_unique<Node>(GridLocation(5, 1), 100, 200);
			auto node2 = make_unique<Node>(GridLocation(4, 4), 100, 300);
			
			auto edge = make_shared<Edge>(*node1.get(), *node2.get(), 10);
			node1->addEdge(edge);

			vector<unique_ptr<Node>> navGraph;

			navGraph.push_back(std::move(node1));
			navGraph.push_back(std::move(node2));

			NavGraphHelper graph(navGraph);
			auto node = graph.getNode(GridLocation(5, 1));
			Assert::IsTrue(navGraph[0].get() == node);
			Assert::IsFalse(navGraph[1].get() == node);
		}
	};
}