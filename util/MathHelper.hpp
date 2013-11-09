#pragma once

// Christopher D. Canfield
// November 2013
// MathHelper.hpp

namespace cdc
{

	namespace MathHelper
	{
		const float pi = 3.14159265359f;

		// Calculates the angle between two points, in radians.
		float angleInRadians(float point1x, float point1y, float point2x, float point2y);

		// Converts degrees to radians.
		template <class T>
		float degreesToRadians(T degrees)
		{
			return static_cast<float>(degrees * pi / 180.f);
		}

		// Converts radians to degrees.
		template <class T>
		float radiansToDegrees(T radians)
		{
			return static_cast<float>(radians * 180.f / pi);
		}
	}
}