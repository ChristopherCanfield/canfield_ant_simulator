#include "stdafx.h"
#include "CppUnitTest.h"
#include "../util/Random.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;


namespace tests
{
	TEST_CLASS(Random_tests)
	{
	public:
		
		TEST_METHOD(Random_create)
		{
			Random rand(5);
		}

		TEST_METHOD(Random_getInteger)
		{
			Random rand(5);

			Assert::AreEqual(79, rand.getInteger(0, 100));
			Assert::AreEqual(11, rand.getInteger(0, 100));
		}

		TEST_METHOD(Random_getInteger2)
		{
			Random rand(500);

			Assert::AreEqual(74, rand.getInteger(0, 100));
			Assert::AreEqual(44, rand.getInteger(0, 100));
		}
	};
}