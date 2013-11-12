#include "stdafx.h"
#include "CppUnitTest.h"
#include "../util/make_unique.hpp"
#include "../sim/nav/GridLocation.hpp"
#include "../sim/nav/Node.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(make_unique_tests)
	{
	public:

		TEST_METHOD(make_unique_0)
		{
			class ZeroArg {
			public:
				ZeroArg() : 
					val(10) {}
				int getVal() const { return val; }
			private:
				int val;
			};

			auto test = make_unique<ZeroArg>();
			Assert::AreEqual(10, test->getVal());
		}
		
		TEST_METHOD(make_unique_1)
		{
			auto test = make_unique<int>(1);
			Assert::AreEqual(1, *test);
		}

		TEST_METHOD(make_unique_2)
		{
			auto test = make_unique<GridLocation>(1, 2);
			Assert::AreEqual(2u, test->getColumn());
		}

		TEST_METHOD(make_unique_3)
		{
			auto test = make_unique<Node>(GridLocation(1, 2), 100, 200);
			Assert::AreEqual(2u, test->getColumn());
			Assert::AreEqual(100, test->getPixelX());
		}

		TEST_METHOD(make_unique_4)
		{
			class FourArg
			{
			public:
				FourArg(int a, int b, int c, int d) :
					a(a), b(b), c(c), d(d) {}
				int getA() { return a; } 
			private:
				int a;
				int b;
				int c;
				int d;
			};

			auto test = make_unique<FourArg>(1, 2, 3, 4);
			Assert::AreEqual(1, test->getA());
		}
	};
}