#include "PmergeMe.hpp"

int	main( void )
{
	std::vector<int>	vec;
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(7);
	
	std::cout << "Original vector: ";
	for (size_t i = 0; i < 100; i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	mergeInsertionSort(vec);

	std::cout << "Sorted vector: ";
	for (size_t i = 0; i < 100; i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	return 0;
}