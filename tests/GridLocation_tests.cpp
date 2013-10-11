#include "stdafx.h"
#include "CppUnitTest.h"

#include "../util/nav/GridLocation.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(GridLocation_tests)
	{
	public:
		
		TEST_METHOD(GridLocation_create)
		{
			GridLocation grid(5, 10);
		}

		TEST_METHOD(GridLocation_getRow)
		{
			GridLocation grid(5, 10);
			Assert::AreEqual(grid.getRow(), 5u);
		}

		TEST_METHOD(GridLocation_getColumn)
		{
			GridLocation grid(5, 10);
			Assert::AreEqual(grid.getColumn(), 10u);
		}

		TEST_METHOD(GridLocation_equal)
		{
			GridLocation grid(5, 10);
			GridLocation grid2(5, 10);
			Assert::IsTrue(grid == grid2);
		}

		TEST_METHOD(GridLocation_notEqual)
		{
			GridLocation grid(5, 10);
			GridLocation grid2(10, 10);
			Assert::IsTrue(grid != grid2);
		}
	};
}