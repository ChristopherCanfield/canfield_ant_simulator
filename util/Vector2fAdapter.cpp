#include "Vector2fAdapter.hpp"

using cdc::Vector2fAdapter;


Vector2fAdapter::Vector2fAdapter(uint x, uint y) :
	sf::Vector2f(static_cast<float>(x), static_cast<float>(y))
{
}
