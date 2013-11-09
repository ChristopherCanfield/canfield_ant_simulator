#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sim/goal/AntFindFood.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(AntFindFood_tests)
	{
	public:
		
		TEST_METHOD(AntFindFood_create)
		{
			AntFindFood goal;
		}

		TEST_METHOD(AntFindFood_isFinished)
		{
			AntFindFood goal;
			Assert::IsFalse(goal.isFinished());
		}

		TEST_METHOD(AntFindFood_update)
		{
			// TODO: implement this.
			Assert::IsTrue(false);
		}

	};
}