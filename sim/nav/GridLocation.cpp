#include "GridLocation.hpp"

// Christopher D. Canfield
// October 2013
// GridLocation.cpp

using cdc::GridLocation;

bool GridLocation::operator==(const GridLocation& rhs) const 
{
	return (rhs.column == this->column && rhs.row == this->row); 
}

bool GridLocation::operator!=(const GridLocation& rhs) const 
{
	return !(*this == rhs);
}