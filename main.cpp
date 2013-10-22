#include <SFML/Graphics.hpp>

#include "app/App.hpp"
#include "app/GuiTestApp.hpp"
#include "app/AppRunner.hpp"




int main()
{
	GuiTestApp app;
	AppRunner runner;
	runner.execute(app);
	
	return 0;
}