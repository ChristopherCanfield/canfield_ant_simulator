#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sim/goal/AntEat.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(AntEat_tests)
	{
	public:
		
		TEST_METHOD(AntEat_create)
		{
			AntEat goal;
		}

		TEST_METHOD(AntEat_isFinished)
		{
			AntEat goal;
			Assert::IsFalse(goal.isFinished());
		}

		TEST_METHOD(AntEat_update)
		{
			// TODO: implement this.
			Assert::IsTrue(false);
		}

	};
}