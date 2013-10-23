#include <SFML/Graphics.hpp>

#include "app/App.hpp"
#include "app/GuiTestApp.hpp"
#include "app/AppRunner.hpp"
#include "app/AiSimApp.hpp"

#define GUI_TESTS

using cdc::AiSimApp;
using cdc::GuiTestApp;
using cdc::AppRunner;


int main()
{
	#ifdef GUI_TESTS
		GuiTestApp app;
	#else
		AiSimApp app;
	#endif
	
	AppRunner runner;
	runner.execute(app);
	
	return 0;
}