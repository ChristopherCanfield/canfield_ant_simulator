#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sim/goal/AntExplore.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(AntExplore_tests)
	{
	public:
		
		TEST_METHOD(AntExplore_create)
		{
			AntExplore goal;
		}

		TEST_METHOD(AntExplore_isFinished)
		{
			AntExplore goal;
			Assert::IsFalse(goal.isFinished());
		}

		TEST_METHOD(AntExplore_update)
		{
			// TODO: implement this.
			Assert::IsTrue(false);
		}

	};
}