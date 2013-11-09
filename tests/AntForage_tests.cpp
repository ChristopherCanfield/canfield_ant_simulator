#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sim/goal/AntForage.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(AntForage_tests)
	{
	public:
		
		TEST_METHOD(AntForage_create)
		{
			AntForage goal;
		}

		TEST_METHOD(AntForage_isFinished)
		{
			AntForage goal;
			Assert::IsFalse(goal.isFinished());
		}

		TEST_METHOD(AntForage_update)
		{
			// TODO: implement this.
			Assert::IsTrue(false);
		}
	};
}