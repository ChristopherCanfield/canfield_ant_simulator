#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sim/worldobject/AntHome.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(AntHome_tests)
	{
	public:
		
		TEST_METHOD(AntHome_create)
		{
			AntHome home;
		}

		TEST_METHOD(AntHome_getFoundCount)
		{
			AntHome home;
			Assert::AreEqual(0u, home.getFoodCount());
		}

		TEST_METHOD(AntHome_addFood)
		{
			AntHome home;
			home.addFood();
			Assert::AreEqual(1u, home.getFoodCount());
		}

		TEST_METHOD(AntHome_takeFood)
		{
			AntHome home;
			Assert::IsFalse(home.takeFood());
			Assert::AreEqual(0u, home.getFoodCount());

			home.addFood();
			home.addFood();
			Assert::IsTrue(home.takeFood());
			Assert::AreEqual(1u, home.getFoodCount());

			Assert::IsTrue(home.takeFood());
			Assert::AreEqual(0u, home.getFoodCount());
		}
	};
}