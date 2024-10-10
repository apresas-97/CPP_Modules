#ifndef PAIR_UTILS_HPP
#define PAIR_UTILS_HPP

#include <algorithm>
#include <iostream>
#include <functional>

// Sort single pair
template<typename T1, typename T2, typename Compare>
void	sortPair( std::pair<T1, T2> & pair, Compare comp )
{
	if (comp(pair.second, pair.first))
		std::swap(pair.first, pair.second);
}

template<typename T1, typename T2>
void	sortPair( std::pair<T1, T2> & pair )
{
	if (pair.second < pair.first)
		std::swap(pair.first, pair.second);
}

// Sort a container of pairs
template<typename Container, typename Compare>
void	sortPairs( Container & pairs, Compare comp )
{
	typename Container::iterator it = pairs.begin();
	while (it != pairs.end())
	{
		sortPair(*it, comp);
		it++;
	}
}

template<typename Container>
void	sortPairs( Container & pairs )
{
	typename Container::iterator it = pairs.begin();
	while (it != pairs.end())
	{
		sortPair(*it);
		it++;
	}
}

template<typename Compare>
void	sortPairs( std::vector<std::pair<int, int> > & pairs, Compare comp )
{
	sortPairs<std::vector<std::pair<int, int> >, Compare>(pairs, comp);
}

// Print pair
template<typename T1, typename T2>
void	printPair( std::pair<T1, T2> const & pair )
{
	std::cout << "Pair: " << pair.first << " " << pair.second << std::endl;
}

// Print pairs
template<typename T1, typename T2>
void	printPairs( std::pair<T1, T2>* pairs, unsigned int nbPairs )
{
	std::cout << "Printing Pairs:" << std::endl;
	for (unsigned int i = 0; i < nbPairs; i++)
		printPair(pairs[i]);
	std::cout << std::endl;
}

template<typename T1, typename T2, typename Container>
void	printPairs( Container const & pairs )
{
	std::cout << "Printing Pairs:" << std::endl;
	typename Container::const_iterator it = pairs.begin();
	while (it != pairs.end())
	{
		printPair(*it);
		it++;
	}
	std::cout << std::endl;
}

#endif // PAIR_UTILS_HPP