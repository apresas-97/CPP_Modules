#include "PmergeMe.hpp"

static bool	isSorted( list & lst )
{
	if (lst.size() < 2)
		return true;

	list::const_iterator it = lst.begin();
	list::const_iterator next = it;
	++next;

	while (next != lst.end())
	{
		if (*it > *next)
			return false;
		++it;
		++next;
	}

	return true;
}

static bool	isSorted( list::const_iterator first, list::const_iterator last )
{
	if (std::distance(first, last) < 2)
		return true;

	list::const_iterator it = first;
	list::const_iterator next = it;
	++next;

	while (next != last)
	{
		if (*it > *next)
			return false;
		++it;
		++next;
	}

	return true;
}

static bool	isSorted( vector & vec )
{
	if (vec.size() < 2)
		return true;
	
	for (vector::const_iterator it = vec.begin(); it != vec.end() - 1; ++it)
	{
		if (*it > *(it + 1))
			return false;
	}

	return true;
}

static bool	isSorted( vector::const_iterator first, vector::const_iterator last )
{
	if (std::distance(first, last) < 2)
		return true;

	vector::const_iterator it = first;
	vector::const_iterator next = it;
	++next;

	while (next != last)
	{
		if (*it > *next)
			return false;
		++it;
		++next;
	}

	return true;
}

void	verifySort( vector & vec )
{
	if (isSorted(vec))
		std::cout << GREEN BOLD << "Vector is sorted!" << RESET << std::endl;
	else
		std::cout << RED BOLD << "Vector is not sorted!" << RESET << std::endl;
}

void	verifySort( list & lst )
{
	if (isSorted(lst))
		std::cout << GREEN BOLD << "List is sorted!" << RESET << std::endl;
	else
		std::cout << RED BOLD << "List is not sorted!" << RESET << std::endl;
}

void	verifySort( vector::const_iterator first, vector::const_iterator last  )
{
	if (isSorted(first, last))
		std::cout << GREEN BOLD << "Vector is sorted!" << RESET << std::endl;
	else
		std::cout << RED BOLD << "Vector is not sorted!" << RESET << std::endl;
}

void	verifySort( list::iterator first, list::iterator last )
{
	if (isSorted(first, last))
		std::cout << GREEN BOLD << "List is sorted!" << RESET << std::endl;
	else
		std::cout << RED BOLD << "List is not sorted!" << RESET << std::endl;
}
