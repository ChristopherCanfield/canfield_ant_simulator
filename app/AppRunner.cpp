#include "AppRunner.hpp"

#include <stdexcept>
#include <iostream>
#include <iomanip>


using cdc::AppRunner;
using cdc::App;


void AppRunner::execute(App& app)
{
	try 
	{
		app.setup();

		// Loop until app.run() returns false.
		while (app.run()) {}

		app.teardown();
	}
	catch (const std::exception& e)
	{
		std::cout << "An exception has occurred:\n";
		std::cout << e.what() << std::endl;
	}
}
