#include "easyfind.hpp"

const char*	NotFoundException::what() const throw()
{
	return "Element not found";
}

const char*	EmptyContainerException::what() const throw()
{
	return "Container is empty";
}
