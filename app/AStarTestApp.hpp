#pragma once

#include "App.hpp"

// Christopher D. Canfield
// November 2013
// AStarTestApp.hpp


namespace cdc
{

	class AStarTestApp :
			public App
	{
	public:
		AStarTestApp();

		virtual void setup() override;

		virtual bool run() override;

		virtual void teardown() override;
	};
}
