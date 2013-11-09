#include "MathHelper.hpp"

#include <cmath>

// Christopher D. Canfield
// November 2013
// MathHelper.cpp




float cdc::MathHelper::angleInRadians(float point1x, float point1y, float point2x, float point2y)
{
	float deltaX = point2x - point1x;
	float deltaY = point2y - point1y;
	return std::atan2(deltaY, deltaX);
}