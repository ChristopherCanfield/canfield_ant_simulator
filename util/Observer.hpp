#pragma once



// An object that can monitor the status of an Observable.
template <class T>
class Observer
{
public:
	update(T observable);
};