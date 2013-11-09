#pragma once

// Christopher D. Canfield
// November 2013
// MathHelper.hpp

namespace cdc
{

	namespace MathHelper
	{
		// Calculates the angle between two points, in radians.
		float angleInRadians(float point1x, float point1y, float point2x, float point2y);

		// Converts degrees to radians.
		float degreesToRadians(float degrees);

		// Converts radians to degrees.
		float radiansToDegrees(float radians);
	}
}