#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/agent/Ant.hpp"
#include "../gui/GuiEventManager.hpp"
#include "../sim/knowledge/GenericPercept.hpp"
#include "../sim/worldobject/AntHome.hpp"
#include "../sim/nav/Node.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

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
			
			Ant ant(manager, home);
		}

		TEST_METHOD(Ant_update)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			
			Ant ant(manager, home);

			GenericPercept percept;
			ant.update(10, percept);
		}

		TEST_METHOD(Ant_getLastKnownFoodPosition)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			
			Ant ant(manager, home);

			Assert::IsTrue(nullptr == ant.getLastKnownFoodPosition());
		}

		TEST_METHOD(Ant_getHunger)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			
			Ant ant(manager, home);

			Assert::AreEqual(0u, ant.getHunger());
		}

		TEST_METHOD(Ant_getHome)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			
			Ant ant(manager, home);

			Assert::IsTrue(&home == &ant.getHome());
		}

		TEST_METHOD(Ant_getNode)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			
			Ant ant(manager, home);

			Assert::IsTrue(nullptr == ant.getNode());
		}

		TEST_METHOD(Ant_isDead)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			
			Ant ant(manager, home);

			Assert::IsFalse(ant.isDead());
		}

		TEST_METHOD(Ant_kill)
		{
			GuiEventManager manager;
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntHome home(node);
			
			Ant ant(manager, home);
			
			ant.kill();
			Assert::IsTrue(ant.isDead());
		}
	};
}