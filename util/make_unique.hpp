#pragma once

#include <memory>


// Christopher D. Canfield
// November 2013
// make_unique.hpp
// make_unique is missing from the c++11 standard.
// Adapted from Herb Sutter: http://herbsutter.com/gotw/_102/
// However, VS2012 does not support variadic templates.


template<class T>
std::unique_ptr<T> make_unique()
{
	return std::unique_ptr<T>(new T());
}

template<class T, class Arg1>
std::unique_ptr<T> make_unique(Arg1&& arg1)
{
	return std::unique_ptr<T>(new T(std::forward<Arg1>(arg1)));
}

template<class T, class Arg1, class Arg2>
std::unique_ptr<T> make_unique(Arg1&& arg1, Arg2&& arg2)
{
	return std::unique_ptr<T>(new T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2)));
}

template<class T, class Arg1, class Arg2, class Arg3>
std::unique_ptr<T> make_unique(Arg1&& arg1, Arg2&& arg2, Arg3&& arg3)
{
	return std::unique_ptr<T>(new T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2),
									std::forward<Arg3>(arg3)));
}

template<class T, class Arg1, class Arg2, class Arg3, class Arg4>
std::unique_ptr<T> make_unique(Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4)
{
	return std::unique_ptr<T>(new T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2),
									std::forward<Arg3>(arg3), std::forward<Arg4>(arg4)));
}

template<class T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5>
std::unique_ptr<T> make_unique(Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5)
{
	return std::unique_ptr<T>(new T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2),
									std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5)));
}