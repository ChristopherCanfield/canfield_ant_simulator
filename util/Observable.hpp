#pragma once

#include "Observer.hpp"

template <class T>
class Observable
{
public:
	// Adds an observer.
	virtual void addObserver(const Observer& o) = 0;
	// Removes an observer.
	virtual void removeObserver(const Observer& o) = 0;
};