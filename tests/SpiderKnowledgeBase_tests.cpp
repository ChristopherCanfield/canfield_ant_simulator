#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/knowledge/SpiderKnowledgeBase.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(SpiderKnowledgeBase_tests)
	{
	public:
		
		TEST_METHOD(SpiderKnowledgeBase_create)
		{
			SpiderKnowledgeBase kb;
		}

	};
}