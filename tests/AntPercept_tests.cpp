#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/knowledge/AntPercept.hpp"
#include "../sim/knowledge/GenericPercept.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(AntPercept_tests)
	{
	public:
		
		TEST_METHOD(AntPercept_genericToAntPercept)
		{
			GenericPercept percept;
			AntPercept antPercept(percept);
		}

	};
}