#pragma once

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