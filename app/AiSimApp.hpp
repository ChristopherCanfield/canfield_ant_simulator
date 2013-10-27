#pragma once

// Christopher D. Canfield
// October 2013
// AiSimApp.hpp

#include "App.hpp"


namespace cdc 
{

	class AiSimApp :
			public App
	{
	public:
		AiSimApp();
		~AiSimApp();

		virtual void setup() override;

		virtual bool run() override;

		virtual void teardown() override;
	};

}