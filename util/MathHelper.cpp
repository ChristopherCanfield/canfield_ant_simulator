#include "MathHelper.hpp"

#include <cmath>

// Christopher D. Canfield
// November 2013
// MathHelper.cpp


const float pi = 3.14159265359f;

float cdc::MathHelper::angleInRadians(float point1x, float point1y, float point2x, float point2y)
{
	float deltaX = point1x - point2x;
	float deltaY = point1y - point2y;
	return std::atan2(deltaY, deltaX);
}

float cdc::MathHelper::degreesToRadians(float degrees)
{
	return (degrees * pi / 180.f);
}

float cdc::MathHelper::radiansToDegrees(float radians)
{
	return (radians * 180.f / pi);
}