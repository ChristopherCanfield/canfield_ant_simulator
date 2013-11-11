#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sim/nav/NavGraph.hpp"
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
		
		TEST_METHOD(NavGraph_create)
		{
			GridLocation location(5, 1);
			auto node1 = make_unique<Node>(location, 100, 200);
			auto node2 = make_unique<Node>(location, 100, 300);
			
			auto edge = make_shared<Edge>(*node1.get(), *node2.get(), 10);
			node1->addEdge(edge);

			vector<unique_ptr<Node>> navGraph;

			navGraph.push_back(std::move(node1));
			navGraph.push_back(std::move(node2));

			NavGraph graph(move(navGraph));
		}

		TEST_METHOD(NavGraph_isValid)
		{
			auto node1 = make_unique<Node>(GridLocation(5, 1), 100, 200);
			auto node2 = make_unique<Node>(GridLocation(4, 4), 100, 300);
			
			auto edge = make_shared<Edge>(*node1.get(), *node2.get(), 10);
			node1->addEdge(edge);

			vector<unique_ptr<Node>> navGraph;

			navGraph.push_back(std::move(node1));
			navGraph.push_back(std::move(node2));

			NavGraph graph(std::move(navGraph));
			Assert::IsTrue(graph.isValid(GridLocation(5, 1)));
			Assert::IsFalse(graph.isValid(GridLocation(1, 5)));
			Assert::IsFalse(graph.isValid(GridLocation(2, 2)));
			Assert::IsTrue(graph.isValid(GridLocation(4, 4)));
			Assert::IsFalse(graph.isValid(GridLocation(4, 3)));
		}
	};
}