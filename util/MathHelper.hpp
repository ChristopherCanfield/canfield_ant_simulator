#pragma once

#include <cmath>

// Christopher D. Canfield
// November 2013
// MathHelper.hpp

namespace cdc
{

	namespace MathHelper
	{
		const float pi = 3.14159265359f;

		// Calculates the angle between two points, in radians.
		template <class Point1Type, class Point2Type>
		float angleInRadians(Point1Type point1x, Point1Type point1y, Point2Type point2x, Point2Type point2y)
		{
			float deltaX = static_cast<float>(point2x) - static_cast<float>(point1x);
			float deltaY = static_cast<float>(point2y) - static_cast<float>(point1y);
			return std::atan2(deltaY, deltaX);
		}

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