#pragma once

// Christopher D. Canfield
// October 2013
// Percept.hpp

#include "Percept.hpp"


namespace cdc
{
	// The percept received by spiders.
	class SpiderPercept :
			public Percept
	{
	public:
		// Converts a percept into a spider percept.
		SpiderPercept(const Percept& percept);
		~SpiderPercept();
	};
}
