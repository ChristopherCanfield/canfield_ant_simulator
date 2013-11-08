#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sim/worldobject/AntFoodPile.hpp"
#include "../sim/nav/Node.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;


namespace tests
{
	TEST_CLASS(AntFoodPile_tests)
	{
	public:
		
		TEST_METHOD(AntFoodPile_create)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntFoodPile food(10u, node);
		}

		TEST_METHOD(AntFoodPile_getFoundCount)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntFoodPile food(10u, node);

			Assert::AreEqual(10u, food.getFoodCount());
		}

		TEST_METHOD(AntFoodPile_takeFood)
		{
			GridLocation location(5, 1);
			Node node(location, 100, 200);
			AntFoodPile food(4u, node);

			Assert::IsTrue(food.takeFood());
			Assert::AreEqual(3u, food.getFoodCount());

			food.takeFood();
			food.takeFood();
			Assert::IsTrue(food.takeFood());
			Assert::AreEqual(0u, food.getFoodCount());

			Assert::IsFalse(food.takeFood());
			Assert::AreEqual(0u, food.getFoodCount());
		}

	};
}