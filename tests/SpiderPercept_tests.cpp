#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/knowledge/SpiderPercept.hpp"
#include "../sim/knowledge/GenericPercept.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(SpiderPercept_tests)
	{
	public:
		
		TEST_METHOD(SpiderPercept_genericToSpiderPercept)
		{
			GenericPercept percept;
			SpiderPercept spiderPercept(percept);
		}

	};
}