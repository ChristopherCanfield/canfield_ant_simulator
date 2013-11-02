#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/goal/AntGoal.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(AntGoal_tests)
	{
	public:
		
		TEST_METHOD(AntGoal_create)
		{
			AntGoal antGoal();
		}

		TEST_METHOD(AntGoal_update)
		{
			// TODO: create the AntGoal::update test.
			Assert::IsTrue(false);
		}
	};
}