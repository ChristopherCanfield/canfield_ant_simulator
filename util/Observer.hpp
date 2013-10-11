#pragma once

// Christopher D. Canfield
// October 2013
// Observer.hpp


// An object that can monitor the status of an Observable.
template <class T>
class Observer
{
public:
	virtual void update(T& observable) = 0;
};
