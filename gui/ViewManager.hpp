#pragma once

// Christopher D. Canfield
// October 2013
// ViewManager.hpp

#include "GuiEventObserver.hpp"
#include "GuiEventManager.hpp"

namespace cdc
{

	class ViewManager :
			public GuiEventObserver
	{
	public:
		ViewManager();
		~ViewManager();


	};
}
