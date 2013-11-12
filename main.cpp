#include "app/App.hpp"
#include "app/GuiTestApp.hpp"
#include "app/AppRunner.hpp"
#include "app/AiSimApp.hpp"
#include "app/AStarTestApp.hpp"
#include "app/AntGoalTestApp.hpp"

#include <SFML/Graphics.hpp>

// Define GUI_TESTS to run the gui test app.
//#define GUI_TESTS
// Or, define SEARCH_TESTS to run the search test app.
//#define SEARCH_TESTS
// Or, define GOAL_TESTS to run the goal test app.
//#define GOAL_TESTS
// Or, define none of the above to run the simulator.

using cdc::AiSimApp;
using cdc::GuiTestApp;
using cdc::AppRunner;
using cdc::AStarTestApp;
using cdc::AntGoalTestApp;


int main()
{
	#if defined(GUI_TESTS)
		GuiTestApp app;
	#elif defined(SEARCH_TESTS)
		AStarTestApp app;
	#elif defined(GOAL_TESTS)
		AntGoalTestApp app;
	#else
		AiSimApp app;
	#endif
	
	AppRunner runner;
	runner.execute(app);
	
	return 0;
}