#include "stdafx.h"
#include "CppUnitTest.h"

#include "../sim/knowledge/AntKnowledgeBase.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(AntKnowledgeBase_tests)
	{
	public:
		
		TEST_METHOD(AntKnowledgeBase_create)
		{
			AntKnowledgeBase kb;
		}

	};
}