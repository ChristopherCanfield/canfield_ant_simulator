#pragma once

#include "Percept.hpp"


namespace cdc
{

	class AntPercept :
			public Percept
	{
	public:
		// Converts a percept into an ant percept.
		AntPercept(const Percept& percept);
		~AntPercept();
	};
}