#include "stdafx.h"
#include "CppUnitTest.h"
#include "../util/ObservableVector2.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(ObservableVector2_tests)
	{
	public:
		
		TEST_METHOD(ObservableVector2_get_set)
		{
			ObservableVector2 v;
			v.set(5, 10);
			Assert::AreEqual(5.f, v.getX());
			Assert::AreEqual(10.f, v.getY());
		}

		TEST_METHOD(ObservableVector2_get_set2)
		{
			ObservableVector2 v;
			v.set(5, 10);
			Assert::AreEqual(5.f, v.get().x);
			Assert::AreEqual(10.f, v.get().y);
		}

		TEST_METHOD(ObservableVector2_get_set3)
		{
			ObservableVector2 v;
			v.set(5, 10);
			auto vec = v.get();
			Assert::IsTrue(vec == v.get());
		}
	};
}