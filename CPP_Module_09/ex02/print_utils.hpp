#ifndef PRINT_UTILS_HPP
#define PRINT_UTILS_HPP

#include <iostream>
#include <vector>
#include <list>

template<typename Container>
void	printContainer( Container const & container, std::string name )
{
	std::cout << "Printing " << name << ":" << std::endl;
	typename Container::const_iterator it = container.begin();
	while (it != container.end())
	{
		std::cout << *it << " " << std::endl;
		it++;
	}
	std::cout << std::endl;
}

template<typename Container>
void	printContainerPairs( Container const & container, std::string name )
{
	std::cout << "Printing " << name << ":" << std::endl;
	typename Container::const_iterator it = container.begin();
	while (it != container.end())
	{
		std::cout << it->first << " " << std::endl;
		it++;
	}
	std::cout << std::endl;
}

// template<typename T>
// void	printVector( std::vector<T> const & vec )
// {
// 	printContainer(vec, "std::vector");
// }

// template<typename T>
// void	printList( std::list<T> const & list )
// {
// 	printContainer(list, "std::list");
// }

/////////////////

void	printVector( std::vector<std::pair<int, int> >::iterator begin, std::vector<std::pair<int, int> >::iterator end )
{
	std::vector<std::pair<int, int> >::iterator	it = begin;
	std::cout << "a:\t";
	while (it != end)
	{
		if (it + 1 != end)
			std::cout << it->first << " -> ";
		else
			std::cout << it->first;
		it++;
	}
	std::cout << std::endl;
	std::cout << "  \t";
	it = begin;
	while (it != end)
	{
		std::cout << "|    ";
		it++;
	}
	it = begin;
	std::cout << std::endl;
	std::cout << "b:\t";
	while (it != end)
	{
		if (it + 1 != end)
			std::cout << it->second << " -> ";
		else
			std::cout << it->second;
		it++;
	}
	std::cout << std::endl;
}

void	printVector( std::vector<int>::iterator begin, std::vector<int>::iterator end )
{
	std::vector<int>::iterator	it = begin;
	while (it != end)
	{
		if (it + 1 != end)
			std::cout << *it << " -> ";
		else
			std::cout << *it;
		it++;
	}
	std::cout << std::endl;
}

void	printPairs( std::vector<std::pair<int, int> >::iterator begin, std::vector<std::pair<int, int> >::iterator end )
{
	std::vector<std::pair<int, int> >::iterator	it = begin;
	while (it != end)
	{
		std::cout << it->first << " -> " << it->second << std::endl;
		it++;
	}
}

#endif // PRINT_UTILS_HPP