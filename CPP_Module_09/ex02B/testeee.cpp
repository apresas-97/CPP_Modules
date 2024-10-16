#include <iostream>
#include <vector>

// #include "MIterator.hpp"

// int	main()
// {
// 	std::vector<int>	vec;
// 	for (size_t i = 1; i <= 100; i++)
// 		vec.push_back(i);

// 	MIterator<std::vector<int>::iterator>	it(vec.begin(), 10);

// 	std::cout << "it.base() = " << *it.base() << std::endl;

// 	std::cout << "It = " << *it << std::endl;
// 	it += 1;
// 	std::cout << "It = " << *it << std::endl;
// 	it += 1;
// 	std::cout << "It = " << *it << std::endl;

//     return 0;
// }

#include <list>

int	main( void )
{
	std::list<int>	lst;
	for (size_t i = 1; i <= 25; i++)
		lst.push_back(i);
	
	std::cout << "Original list: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::list<int>::iterator	it = lst.begin();

	std::cout << "it = " << *it << std::endl;

	std::list<int>::iterator	it2 = it;
	lst.insert(it2, 100);
	lst.insert(it2, 100);
	lst.insert(it2, 100);
	it2 = lst.begin();
	std::advance(it2, 4);
	lst.insert(it2, 200);

	std::cout << "After insert:  ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "it = " << *it << std::endl;


	return 0;
}
