#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/knowledge/GenericPercept.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(GenericPercept_tests)
	{
	public:
		
		TEST_METHOD(GenericPercept_create)
		{
			GenericPercept percept;
		}

	};
}