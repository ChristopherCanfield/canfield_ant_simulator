#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/agent/Ant.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../sim/knowledge/GenericPercept.hpp"
#include "../sim/worldobject/AntHome.hpp"
#include "../sim/nav/Node.hpp"
#include "../sim/nav/NavGraphHelper.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;
using namespace std;

namespace tests
{
	TEST_CLASS(Ant_tests)
	{
	public:
		
		TEST_METHOD(Ant_create)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			vector<Node> vec;
			NavGraphHelper graph(vec);
			
			Ant ant(manager, home, graph);
		}

		TEST_METHOD(Ant_update)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			vector<Node> vec;
			NavGraphHelper graph(vec);
			
			Ant ant(manager, home, graph);

			GenericPercept percept;
			ant.update(10, percept);
		}

		TEST_METHOD(Ant_getLastKnownFoodPosition)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			vector<Node> vec;
			NavGraphHelper graph(vec);
			
			Ant ant(manager, home, graph);

			Assert::IsTrue(nullptr == ant.getLastKnownFoodPosition());
		}

		TEST_METHOD(Ant_getHunger)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			vector<Node> vec;
			NavGraphHelper graph(vec);

			Ant ant(manager, home, graph);

			Assert::AreEqual(0u, ant.getHunger());
		}

		TEST_METHOD(Ant_getHome)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			vector<Node> vec;
			NavGraphHelper graph(vec);
			
			Ant ant(manager, home, graph);

			Assert::IsTrue(&home == &ant.getHome());
		}

		TEST_METHOD(Ant_getNode)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			vector<Node> vec;
			NavGraphHelper graph(vec);
			
			Ant ant(manager, home, graph);

			Assert::IsTrue(nullptr == ant.getNode());
		}

		TEST_METHOD(Ant_isDead)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			vector<Node> vec;
			NavGraphHelper graph(vec);
			
			Ant ant(manager, home, graph);

			Assert::IsFalse(ant.isDead());
		}

		TEST_METHOD(Ant_kill)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			vector<Node> vec;
			NavGraphHelper graph(vec);
			
			Ant ant(manager, home, graph);
			
			ant.kill();
			Assert::IsTrue(ant.isDead());
		}
	};
}