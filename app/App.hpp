#pragma once

// Christopher D. Canfield
// October 2013
// App.hpp

namespace cdc 
{

	class App
	{
	public:
		virtual ~App() {}

		// Called when the app is launched.
		virtual void setup() = 0;

		// Called continuously until this returns false.
		virtual bool run() = 0;

		// The final method that is called before the app is shut down.
		virtual void teardown() = 0;
	};

}