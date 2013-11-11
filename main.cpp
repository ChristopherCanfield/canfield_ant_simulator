#include "app/App.hpp"
#include "app/GuiTestApp.hpp"
#include "app/AppRunner.hpp"
#include "app/AiSimApp.hpp"
#include "app/AStarTestApp.hpp"

#include <SFML/Graphics.hpp>

// Define GUI_TESTS to run the gui test app.
//#define GUI_TESTS
// Or, define SEARCH_TESTS to run the search test app.
//#define SEARCH_TESTS
// Or, define neither to run the simulator.

using cdc::AiSimApp;
using cdc::GuiTestApp;
using cdc::AppRunner;
using cdc::AStarTestApp;


int main()
{
	#if defined(GUI_TESTS)
		GuiTestApp app;
	#elif defined(SEARCH_TESTS)
		AStarTestApp app;
	#else
		AiSimApp app;
	#endif
	
	AppRunner runner;
	runner.execute(app);
	
	return 0;
}