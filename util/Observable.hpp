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
		void addObserver(cdc::Observer<T>& o);
	
		// Removes an observer.
		void removeObserver(const cdc::Observer<T>& o);

	protected:
		std::vector<cdc::Observer<T>*> observers;

		void notifyObservers(T& notification);
	};


	template <class T>
	void Observable<T>::addObserver(cdc::Observer<T>& o)
	{
		observers.push_back(&o);
	}

	template <class T>
	void Observable<T>::removeObserver(const cdc::Observer<T>& o)
	{
		for (auto observer : observers)
		{
			if (*observer == &o)
			{
				observers.erase(&o);
				return;
			}
		}
	}

	template <class T>
	void Observable<T>::notifyObservers(T& notification)
	{
		for (auto i = 0; i < observers.size(); ++i)
		{
			observers[i]->update(notification);
		}

		//for (auto observer : observers)
		//{
		//	(*observer).update(*this);
		//}
	}
}