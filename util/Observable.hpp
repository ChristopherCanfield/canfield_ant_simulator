#pragma once

#include "Observer.hpp"


class Observable
{
public:

	virtual void addObserver(const Observer& o) = 0;

	virtual void removeObserver(const Observer& o) = 0;
};