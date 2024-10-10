#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <sstream>
#include "pair_utils.hpp"
#include "utils_idk.hpp"
#include "print_utils.hpp"

void	printArray( std::string const & prefix, int *array, int size )
{
	std::stringstream ss;
		ss << prefix;
	for (int i = 0; i < size; i++)
	{
		ss << array[i];
		if (i < size - 1)
			ss << " ";
	}
	std::cout << ss.str() << std::endl;
}

size_t	getNextJacobsthalNumber( void )
{
	static size_t	currentNumber = 0;
	static size_t	nextNumber = 1;
	size_t			tmp = currentNumber;

	currentNumber = nextNumber;
	nextNumber += 2 * tmp;

	return tmp;
}

void	binaryInsert( std::vector<int> & vec, int value )
{
	size_t	i = vec.size() - 2;
	if (value >= vec[i])
	{
		if (value >= vec[i + 1])
			vec.push_back(value);
		else // value < vec[i + 1]
			vec.insert(vec.begin() + (i + 1), value);
	}
	else // value < vec[i]
	{
		if (value >= vec[i - 1])
			vec.insert(vec.begin() + i, value);
		else // value < vec[i - 1]
			vec.insert(vec.begin() + (i - 1), value);
	}
}

// mergeInsertionSort, called with iterators
template<typename Iterator>
void	mergeInsertionSortVector( Iterator begin, Iterator end )
{
	std::cout << "Entering mergeInsertionSortVector" << std::endl;
	std::cout << "Received vector:" << std::endl;
	printVector(begin, end);


	size_t	size = std::distance(begin, end);
	if (size < 2) // Maybe?
		return ;


	// Maybe have a bool has_stray if size is odd, then
	// redefine end to be end - 1, but keep track of the original end

	// Step 1: Create pairs
	size_t	nbPairs = size / 2;
	std::vector<std::pair<int, int> >	mainChain = makePairVector(begin, end);

	std::cout << "pairs:" << std::endl;
	printPairs(mainChain.begin(), mainChain.end());

	sortPairs(mainChain, std::less<int>()); // Suspicious

	std::cout << "sorted mainChain:" << std::endl;
	printVector(mainChain.begin(), mainChain.end());
	std::cout << std::endl;

	// Sort it recursively (based on their lowest value(which is the first element, since we just sorted them like such))
	std::cout << "Sorting recursively:" << std::endl;
	if (mainChain.size() > 1)
		mergeInsertionSortVector(mainChain.begin(), mainChain.end());
	std::cout << "Recursion OUT" << std::endl;

	// After you have come out of the recursion, you must merge the pairs
	// into the original container I think

	// Insert b1, which will always be smaller than a1


	std::vector<int> vecChain;
	for (size_t i = 0; i < mainChain.size(); i++)
		vecChain.push_back(mainChain[i].first);

	// insert b1
	std::cout << "Inserting b1" << std::endl;
	
	size_t	b_end = size - vecChain.size() - 1;
	size_t	i = b_end - getNextJacobsthalNumber();
	size_t	auxNextJacobsthalNumber = getNextJacobsthalNumber();
	std::cout << "b_end = " << b_end << std::endl;
	std::cout << "nextJacobsthalNumber = " << auxNextJacobsthalNumber << std::endl;
	vecChain.push_back(mainChain[i].second); // insert b1
	printVector(vecChain.begin(), vecChain.end());
	while (i >= 0)
	{
		std::cout << "Starting loop" << std::endl;
		// std::cout << "Check" << std::endl;
		std::cout << "i = " << i << std::endl;
		std::cout << "b_end = " << b_end << std::endl;
		size_t	i = b_end - getNextJacobsthalNumber();
		size_t	next_end = 0;
		while (i != b_end)
		{
			binaryInsert(vecChain, mainChain[i].second);
			next_end++;
			i++;
		}
		std::cout << "next_end = " << getNextJacobsthalNumber() << std::endl;
		b_end -= next_end;
		std::cout << "loop!" << std::endl;
	}

}

int	main( int argc, char **argv )
{
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe \"expression\"" << std::endl;
		return 1;
	}
	int	size = argc - 1;
	int	*numbers = new int[size];
	for (int i = 0; i < size; i++)
	{
		std::stringstream ss(argv[i + 1]);
		ss >> numbers[i];
		if (ss.fail() || !ss.eof())
		{
			std::cout << "Invalid input" << std::endl;
			return 1;
		}
	}
	printArray("Before:\t", numbers, size);

	std::vector<int> vec(numbers, numbers + size);
	
	mergeInsertionSortVector(vec.begin(), vec.end());

	printArray("After:\t", numbers, size);
	// printTime(0);
	// printTime(1);

	delete [] numbers;
	return 0;
}
