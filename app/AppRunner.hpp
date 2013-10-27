#pragma once

#include "App.hpp"

// Christopher D. Canfield
// October 2013
// AppRunner.hpp


namespace cdc 
{

	class AppRunner
	{
	public:
		AppRunner() {}
		~AppRunner() {}

		void execute(App& app);
	};

}