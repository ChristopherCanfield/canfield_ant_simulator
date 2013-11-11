#pragma once

// Christopher D. Canfield
// October 2013
// GridLocation.hpp

#include "../util/Typedefs.hpp"

#include <functional>


namespace cdc 
{
	// A row,column location on the navigation grid.
	class GridLocation
	{
	public:
		GridLocation() :
			row(0), column(0) {}
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

namespace std
{
	template<>
	class hash<cdc::GridLocation>
	{
	public:
		// Adapted from Bjarne Stroustrup, "A Tour of C++"
		std::size_t operator()(const cdc::GridLocation& key) const
		{
			return hash<uint>()(key.getColumn()) ^
					hash<uint>()(key.getRow());
		}
	};
}