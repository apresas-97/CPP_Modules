#include <iostream>
#include <vector>

#include "MIterator.hpp"

int	main()
{
	std::vector<int>	vec;
	for (size_t i = 1; i <= 100; i++)
		vec.push_back(i);

	MIterator<std::vector<int>::iterator>	it(vec.begin(), 10);

	std::cout << "it.base() = " << *it.base() << std::endl;

	std::cout << "It = " << *it << std::endl;
	it += 1;
	std::cout << "It = " << *it << std::endl;
	it += 1;
	std::cout << "It = " << *it << std::endl;

    return 0;
}
