#pragma once

// Christopher D. Canfield
// October 2013
// Observer.hpp

namespace cdc 
{
	// An object that can monitor the status of an Observable.
	template <class T>
	class Observer
	{
	public:
		// Called when the observable is updated.
		virtual void update(T& observable) = 0;
	};
}