#pragma once

// Christopher D. Canfield
// October 2013
// Observable.hpp

#include "Observer.hpp"

#include <vector>

namespace cdc 
{
	// An interface for an observable object.
	template <class T>
	class Observable
	{
	public:
		// Adds an observer.
		void addObserver(Observer<T>& o);
	
		// Removes an observer.
		void removeObserver(const Observer<T>& o);

	protected:
		std::vector<Observer<T>*> observers;
	};


	template <class T>
	void Observable<T>::addObserver(Observer<T>& o)
	{
		observers.push_back(&o);
	}

	template <class T>
	void Observable<T>::removeObserver(const Observer<T>& o)
	{
		for (auto observer : observers)
		{
			if (observer == &o)
			{
				observers.erase(&o);
			}
		}
	}
}