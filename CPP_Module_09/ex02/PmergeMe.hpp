#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>

#define BEFORE 0
#define AFTER 1

#define LIST 0
#define VECTOR 1

class PmergeMe
{
	public:
		PmergeMe( void );
		PmergeMe( PmergeMe const &other );
		~PmergeMe();
		PmergeMe &operator=( PmergeMe const &other );

	private:

};

void	sortPair( std::pair<int, int> & pair )
{
	if (pair.first > pair.second)
		std::swap(pair.first, pair.second);
}

void	printPairs( std::pair<int, int> *pairs, unsigned int nbPairs )
{
	for (unsigned int i = 0; i < nbPairs; i++)
	{
		std::cout << "Pair " << i << ": ";
		std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
		std::cout << std::endl;
	}
}

void	printVector( std::vector<int> & vec, std::string name )
{
	std::cout << name << ": ";
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void	mergeInsertionSort( typename T::iterator begin, typename T::iterator end )
{
	// Step 1: Pair
	// How many pairs?
	unsigned int	nbPairs = (end - begin) / 2;
	std::cout << "nbPairs = " << nbPairs << std::endl;
	std::pair<int, int>			pair[nbPairs];
	typename T::iterator		it = begin;
	unsigned int	i = 0;
	while (it != end)
	{
		pair[i].first = *it;
		it++;
		if (it != end)
		{
			pair[i].second = *it;
			it++;
		}
		i++;
	}

	std::cout << "Pairs before sorting:" << std::endl;
	printPairs(pair, nbPairs);
	std::cout << std::endl;

	// Step 2: Compare pairs
	for (unsigned int i = 0; i < nbPairs; i++)
		sortPair(pair[i]);

	std::cout << "Pairs after sorting:" << std::endl;
	printPairs(pair, nbPairs);
	std::cout << std::endl;

	// Step 3: Merge largest elements of all pairs into a new array
	std::vector<std::pair<int, int> >	mainChain;
	for (unsigned int i = 0; i < nbPairs; i++)
		mainChain.push_back(pair[i]);
	
	// Sort it recursively
	if (mainChain.size() > 1)
		mergeInsertionSort<std::vector<std::pair<int, int>>>(mainChain.begin(), mainChain.end());

	// Step 4: Repeat until there is only one element left
}

#endif // PMERGEME_HPP
