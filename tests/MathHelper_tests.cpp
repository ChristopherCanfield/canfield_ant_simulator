#include "stdafx.h"
#include "CppUnitTest.h"

#include "../util/MathHelper.hpp"

#include <iostream>
#include <iomanip>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace tests
{
	TEST_CLASS(MathHelper_tests)
	{
	public:
		
		TEST_METHOD(MathHelper_angle1)
		{
			float angle = MathHelper::angleInRadians(1.f, 1.f, 2.f, 2.f);

			std::stringstream s;
			s << std::setprecision(4) << std::setiosflags(std::ios_base::fixed) << angle;
			s >> angle;

			Assert::AreEqual(0.7854f, angle);
		}

		TEST_METHOD(MathHelper_angle2)
		{
			float angle = MathHelper::angleInRadians(1.f, 1.f, 1.f, 2.f);

			std::stringstream s;
			s << std::setprecision(4) << std::setiosflags(std::ios_base::fixed) << angle;
			s >> angle;

			Assert::AreEqual(1.5708f, angle);
		}

		TEST_METHOD(MathHelper_radiansToDegrees1)
		{
			float degrees = MathHelper::radiansToDegrees(1);

			std::stringstream s;
			s << std::setprecision(4) << std::setiosflags(std::ios_base::fixed) << degrees;
			s >> degrees;

			Assert::AreEqual(57.2958f, degrees);
		}

		TEST_METHOD(MathHelper_radiansToDegrees2)
		{
			float degrees = MathHelper::radiansToDegrees(0.5f);

			std::stringstream s;
			s << std::setprecision(4) << std::setiosflags(std::ios_base::fixed) << degrees;
			s >> degrees;

			Assert::AreEqual(28.6479f, degrees);
		}

		TEST_METHOD(MathHelper_degreesToRadians1)
		{
			float radians = MathHelper::degreesToRadians(28.6478898);

			std::stringstream s;
			s << std::setprecision(1) << std::setiosflags(std::ios_base::fixed) << radians;
			s >> radians;

			Assert::AreEqual(0.5f, radians);
		}

		TEST_METHOD(MathHelper_degreesToRadians2)
		{
			float radians = MathHelper::degreesToRadians(57.2957795f);

			Assert::AreEqual(1, static_cast<int>(radians));
		}
	};
}