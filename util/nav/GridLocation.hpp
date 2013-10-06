#pragma once

// Christopher D. Canfield
// October 2013
// GridLocation.hpp

#include "../Typedefs.hpp"


class GridLocation
{
public:
	GridLocation(uint row, uint col) :
		row(row), column(col) {}

	uint getRow() const { return row; }

	uint getColumn() const { return column; }

	bool operator==(const GridLocation &other) const;
	bool operator!=(const GridLocation &other) const;

private:
	uint row;
	uint column;
};
