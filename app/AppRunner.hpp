#pragma once

#include "App.hpp"


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