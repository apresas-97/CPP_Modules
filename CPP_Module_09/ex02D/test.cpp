#include <iostream>
// #include <string>

// void	test_jacobsthalNumbers( void )
// {
// 	size_t	jacobsthalNumbers[63];

// 	jacobsthalNumbers[0] = 0;
// 	jacobsthalNumbers[1] = 1;
// 	for (size_t i = 2; i < 63; i++)
// 		jacobsthalNumbers[i] = (jacobsthalNumbers[i - 1]) + (2 * jacobsthalNumbers[i - 2]);

// 	size_t	jacobsthalDiff[63];

// 	jacobsthalDiff[0] = 2;
// 	jacobsthalDiff[1] = 2;
// 	for (size_t i = 2; i < 63; i++)
// 		jacobsthalDiff[i] = jacobsthalDiff[i - 1] + 2 * jacobsthalDiff[i - 2];

// 	std::cout << "Printing Jacobsthal Numbers:" << std::endl;
// 	for (size_t i = 0; i < 63; i++)
// 		std::cout << jacobsthalNumbers[i] << " ";
// 	std::cout << std::endl;

// 	std::cout << "Printing Jacobsthal Differences:" << std::endl;
// 	for (size_t i = 0; i < 63; i++)
// 		std::cout << jacobsthalDiff[i] << " ";
// 	std::cout << std::endl;
// }

#include <vector>
#include <list>
#include <iterator>
#include "LIterator.hpp"

int	main( void )
{
	// test_jacobsthalNumbers();

	std::cout << "Testing vector iterators" << std::endl;
	std::vector<unsigned int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::cout << "Initial run" << std::endl;
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "it = " << *it << " | " << &(*it) << std::endl;

	std::iter_swap(vec.begin(), vec.begin() + 4);
	vec.erase(vec.begin() + 2);
	vec.insert(vec.begin() + 2, 10);

	std::cout << "Second run" << std::endl;
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "it = " << *it << " | " << &(*it) << std::endl;

	std::cout << "Testing list iterators" << std::endl;
	std::list<unsigned int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(7);
	lst.push_back(8);
	lst.push_back(9);
	lst.push_back(10);

	LIterator	start(lst.begin());
	LIterator	end(lst.end());

	std::cout << "Initial run" << std::endl;
	for (LIterator it = start; it != end; it++)
		std::cout << "it = " << *it << " | " << &(*it) << std::endl;
	// std::cout << "As list iterator" << std::endl;
	// for (std::list<unsigned int>::iterator it = lst.begin(); it != lst.end(); it++)
	// 	std::cout << "it = " << *it << " | " << &(*it) << std::endl;

	// std::list<unsigned int>::iterator itA = lst.begin();
	// std::list<unsigned int>::iterator itB = itA;
	// std::advance(itB, 4);
	swapLIterator(start, start + 2);
	// std::iter_swap(itA, itB);

	std::cout << "Second run" << std::endl;
	for (LIterator it = start; it != end; it++)
		std::cout << "it = " << *it << " | " << &(*it) << std::endl;

	////////////////////////////
	// std::list<LIterator>	chain;
	// chain.push_back(start); // a1
	// chain.push_back(start + 1); // b1

	// std::vector<std::list<LIterator>::iterator>	chainPos;
	std::vector<unsigned int*>	chainPos;
	chainPos.reserve((lst.size() + 1) / 2 - 1);

	// for (LIterator it = start + 2; it != end; it += 2)
	// {
	// 	std::list<LIterator>::iterator position = chain.insert(chain.end(), it + 1);
	// 	chainPos.push_back(position);
	// }

	for (LIterator it = start + 2; it != end; it += 2)
	{
		// std::vector<unsigned int*>::iterator position = &(*it);
		chainPos.push_back(&(*it));
	}

	std::cout << "Checking adresses of elements" << std::endl;
	// std::cout << "> chain:" << std::endl;
	// for (std::list<LIterator>::iterator it = chain.begin(); it != chain.end(); it++)
	// 	std::cout << "it = " << **it << " | " << &(**it) << std::endl;

	std::cout << "> chainPos:" << std::endl;
	for (std::vector<unsigned int*>::iterator it = chainPos.begin(); it != chainPos.end(); it++)
		std::cout << "it = " << **it << " | " << *it << std::endl;
	

	std::cout << "What if I now swap the LIterator elements?" << std::endl;
	swapLIterator(start, start + 2);

	std::cout << "Checking adresses of elements" << std::endl;
	std::cout << "> chainPos:" << std::endl;
	for (std::vector<unsigned int*>::iterator it = chainPos.begin(); it != chainPos.end(); it++)
		std::cout << "it = " << **it << " | " << *it << std::endl;

	return 0;
}