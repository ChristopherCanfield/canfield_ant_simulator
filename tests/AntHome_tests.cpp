#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sim/worldobject/AntHome.hpp"
#include "../sim/nav/Node.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(AntHome_tests)
	{
	public:
		
		TEST_METHOD(AntHome_create)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			AntHome home(node);
		}

		TEST_METHOD(AntHome_getFoundCount)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			AntHome home(node);
			Assert::AreEqual(0u, home.getFoodCount());
		}

		TEST_METHOD(AntHome_addFood)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			AntHome home(node);
			home.addFood();
			Assert::AreEqual(1u, home.getFoodCount());
		}

		TEST_METHOD(AntHome_takeFood)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);

			AntHome home(node);
			Assert::IsFalse(home.takeFood());
			Assert::AreEqual(0u, home.getFoodCount());

			home.addFood();
			home.addFood();
			Assert::IsTrue(home.takeFood());
			Assert::AreEqual(1u, home.getFoodCount());

			Assert::IsTrue(home.takeFood());
			Assert::AreEqual(0u, home.getFoodCount());

			Assert::IsFalse(home.takeFood());
			Assert::AreEqual(0u, home.getFoodCount());
		}
	};
}