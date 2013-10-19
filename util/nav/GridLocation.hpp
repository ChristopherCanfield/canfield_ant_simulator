#pragma once

// Christopher D. Canfield
// October 2013
// GridLocation.hpp

#include "../Typedefs.hpp"

namespace cdc 
{
	// A row,column location on the navigation grid.
	class GridLocation
	{
	public:
		GridLocation(uint row, uint col) :
			row(row), column(col) {}

		// Returns the location's row.
		uint getRow() const { return row; }

		// Returns the location's column.
		uint getColumn() const { return column; }

		bool operator==(const GridLocation &other) const;
		bool operator!=(const GridLocation &other) const;

	private:
		uint row;
		uint column;
	};
}