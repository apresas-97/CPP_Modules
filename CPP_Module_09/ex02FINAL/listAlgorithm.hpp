#include <iostream>
#include <exception>
#include <iterator>
#include <utility>
#include <list>
#include <sstream>
#include <stdint.h> // c++98 compatible, unlike cstdint

typedef std::list<unsigned int> t_list;
typedef t_list::iterator		t_list_it;

void	fordJohnsonAlgorithmList( t_list_it first, t_list_it last )
{
	std::list<t_list_it> listPositions;

	for (t_list_it it = first; it != last; std::advance(it, 1))
		listPositions.push_back(it);

	std::cout << "Printing the list's elements from the iterators" << std::endl;
	for (t_list_it it = first; it != last; std::advance(it, 1))
	{
		std::cout << "it value   = " << *it << std::endl;
		std::cout << "it address = " << reinterpret_cast<uintptr_t>(&(*it)) % 10000 << std::endl;
	}
	std::cout << "Printing the list's elements from listPositions:" << std::endl;	
	for (std::list<t_list_it>::iterator it = listPositions.begin(); it != listPositions.end(); std::advance(it, 1))
	{
		std::cout << "it value   = " << **it << std::endl;
		std::cout << "it address = " << reinterpret_cast<uintptr_t>(&(**it)) % 10000 << std::endl;
	}

	std::cout << "Now, we swap some elements from the range of iterators" << std::endl;
	t_list_it itA = first;
	t_list_it itB = first;
	std::advance(itB, 2);
	std::iter_swap(itA, itB);

	std::cout << "New list:" << std::endl;
	std::cout << "Printing the list's elements from the iterators" << std::endl;
	for (t_list_it it = first; it != last; std::advance(it, 1))
	{
		std::cout << "it value   = " << *it << std::endl;
		std::cout << "it address = " << reinterpret_cast<uintptr_t>(&(*it)) % 10000 << std::endl;
	}
	std::cout << "Printing the list's elements from listPositions:" << std::endl;	
	for (std::list<t_list_it>::iterator it = listPositions.begin(); it != listPositions.end(); std::advance(it, 1))
	{
		std::cout << "it value   = " << **it << std::endl;
		std::cout << "it address = " << reinterpret_cast<uintptr_t>(&(**it)) % 10000 << std::endl;
	}
}