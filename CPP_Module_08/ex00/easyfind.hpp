#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <sstream>

class NotFoundException : public std::exception
{
	public:
		virtual const char * what() const throw();
};

class EmptyContainerException : public std::exception
{
	public:
		virtual const char * what() const throw();
};

template<typename T>
int	easyfind( T const & container, int const find )
{
	if (container.empty())
		throw EmptyContainerException();
	typename T::const_iterator it = std::find( container.begin(), container.end(), find );
	if (it == container.end())
		throw NotFoundException();
	return *it;
}

#endif // EASYFIND_HPP
