#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/goal/AntGoHome.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;


namespace tests
{
	TEST_CLASS(AntGoHome_tests)
	{
	public:
		
		TEST_METHOD(AntGoHome_create)
		{
			AntGoHome goal;
		}

		TEST_METHOD(AntGoHome_isFinished)
		{
			AntGoHome goal;
			Assert::IsFalse(goal.isFinished());
		}

		TEST_METHOD(AntGoHome_update)
		{
			// TODO: implement this.
			Assert::IsTrue(false);
		}
	};
}