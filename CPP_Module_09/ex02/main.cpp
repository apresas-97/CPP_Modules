#include "PmergeMe.hpp"

int	main( int argc, char **argv )
{
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe <elements>" << std::endl;
		return 1;
	}

	try
	{
		int				size = argc - 1;
		integer			numbers[size];
		parseArguments(size, argv, numbers);

		PmergeMe	pm;

		vector	vec(numbers, numbers + size);
		list	lst(numbers, numbers + size);

		printVector(vec, "Before:\t");

		pm.mergeInsertionSort(vec);
		pm.mergeInsertionSort(lst);

		printVector(vec, "After:\t");

		pm.printTimeElapsed();

		// Remember to comment this out before submitting
		verifySort(vec);
		verifySort(lst);
	}
	catch ( const std::exception & e )
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
