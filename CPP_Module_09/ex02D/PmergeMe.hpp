#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <typeinfo>

#include "VIterator.hpp"

class PmergeMe
{
	public:
		PmergeMe( void );
		PmergeMe( PmergeMe const &other );
		~PmergeMe();
		PmergeMe &operator=( PmergeMe const &other );

		size_t	jacobsthalNumbers[63];

	private:

		void	mergeInsertionSort( VIterator first, VIterator last );


};

PmergeMe::PmergeMe( void )
{
	jacobsthalNumbers[0] = 2;
	jacobsthalNumbers[1] = 2;
	for (size_t i = 2; i < 63; i++)
		jacobsthalNumbers[i] = jacobsthalNumbers[i - 1] + 2 * jacobsthalNumbers[i - 2];
	// FOR NOW
}

// /// Testing
// PmergeIt<std::vector<int>::iterator>	makePmergeIt( std::vector<int>::iterator it, size_t size )
// {
// 	return PmergeIt<std::vector<int>::iterator>(it, size);
// }

// PmergeIt<std::list<int>::iterator>	makePmergeIt( std::list<int>::iterator it, size_t size )
// {
// 	return PmergeIt<std::list<int>::iterator>(it, size);
// }

// template<typename Iterator>
// PmergeIt<Iterator>	makePmergeIt( Iterator it, size_t size )
// {
// 	return PmergeIt<Iterator>(it, size);
// }

PmergeIt<std::vector<int>::iterator>	makePmergeIt( std::vector<int>::iterator it, size_t size )
{
	return PmergeIt<std::vector<int>::iterator>(it, size);
}

PmergeIt<std::vector<int>::iterator>	makePmergeIt( PmergeIt<std::vector<int>::iterator> it, size_t size )
{
	return PmergeIt<std::vector<int>::iterator>(it, size);
}

// template<>
// PmergeIt<std::vector<int>::iterator>	makePmergeIt( std::vector<int>::iterator it, size_t size )
// {
// 	return PmergeIt<Iterator>(it, size);
// }

// This will be private
void	PmergeMe::mergeInsertionSort( VIterator first, VIterator last )
{
	////
	static size_t jacobsthal_diff[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };
	////
	size_t	size = last - first;
	if (size < 2)
		return ;
	
	// Do something about the odd element?
	bool	oddSize = size % 2 != 0;
	Iterator	end	 = oddSize ? last - 1 : last; // Needs better naming
	makePairs(first, end);

	// mergeInsertionSort(PmergeIt<Iterator>(first, 2), PmergeIt<Iterator>(end, 2)); // testing the test arg
	mergeInsertionSort(makePmergeIt(first, 2), makePmergeIt(end, 2)); // testing the test arg
	// mergeInsertionSort(PmergeIt<Iterator>(first, 2, 1), PmergeIt<Iterator>(end, 2, 1)); // testing the test arg
	// mergeInsertionSort(makePmergeIt(first, 2), makePmergeIt(end, 2)); // testing the test arg
	// mergeInsertionSort(PmergeIt<Iterator>(first, first.size() * 2), PmergeIt<Iterator>(end, end.size() * 2)); // testing the test arg

	std::list<Iterator>	mainChain; // We use a std::list so its iterators don't invalidate after insertions
	std::vector<typename std::list<Iterator>::iterator>	pend; // Is it really necessary to use vector of list ?

	for (Iterator it = first + 2; it != end; it += 2)
	{
		// pend.push_back(mainChain.insert(mainChain.end(), it + 1));
		typename std::list<Iterator>::iterator tmp = mainChain.insert(mainChain.end(), it + 1);
		pend.push_back(tmp);
	}

	// I still don't understand the logic behind this
	if (oddSize)
		pend.push_back(mainChain.end());

	// Binary Insertion part
	Iterator	current = first + 2;
	typename std::vector<typename std::list<Iterator>::iterator>::iterator	current_pend = pend.begin(); // Must fix this Iterator type

	for (size_t k = 0; ; ++k)
	{
		long	dist = jacobsthal_diff[k];
		if (dist > std::distance(current_pend, pend.end())) // Don't get it
			break ;
		
		Iterator	it = current + dist * 2; // ?
		typename std::vector<typename std::list<Iterator>::iterator>::iterator	pe = current_pend + dist; // ????
		
		do
		{
			--pe;
			typename std::list<Iterator>::iterator insertion_point = std::upper_bound(mainChain.begin(), *pe, *it);

			mainChain.insert(insertion_point, it);
		} while (current_pend != pe);

		std::advance(current, dist * 2);
		std::advance(current_pend, dist);
	}

	// Insert the remaining elements
	while (current_pend != pend.end())
	{
		typename std::list<Iterator>::iterator	insertion_point = std::upper_bound(mainChain.begin(), *current_pend, **current_pend);
		mainChain.insert(insertion_point, **current_pend);
		current += 2;
		++current_pend;
	}

	// Copy the sorted elements to a cache then back to origin
	// std::vector<typename std::iterator_traits<Iterator>::value_type>	cache;
	// cache.reserve(size);

	// for (typename std::list<Iterator>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
	// {
	// 	typename std::list<Iterator>::iterator begin = it.base();
	// 	typename std::list<Iterator>::iterator end = begin + it.size();
	// 	// std::move(begin, end, std::back_inserter(cache));
	// 	while (begin != end)
	// 		cache.push_back(*begin++);
	// }
	// // std::move(cache.begin(), cache.end(), first.base());
	// Iterator	origin_it = first;
	// for (Iterator it = cache.begin(); it != cache.end(); it++)
	// {
	// 	origin_it = it;
	// 	origin_it++;
	// }
}

template<>
void	mergeInsertionSort( std::vector<int>::iterator begin, std::vector<int>::iterator end )
{
	PmergeIt<std::vector<int>::iterator>	begin2(begin, 1);
	PmergeIt<std::vector<int>::iterator>	end2(end, 1);
	mergeInsertionSort(begin2, end2); 
}

template<>
void	mergeInsertionSort( std::list<int>::iterator begin, std::list<int>::iterator end )
{
	PmergeIt<std::list<int>::iterator>	begin2(begin, 1);
	PmergeIt<std::list<int>::iterator>	end2(end, 1);
	mergeInsertionSort(begin2, end2); 
}

void	mergeInsertionSort( std::vector<int> & vec )
{
	PmergeIt<std::vector<int>::iterator>	begin(vec.begin(), 1);
	PmergeIt<std::vector<int>::iterator>	end(vec.end(), 1);
	mergeInsertionSort(begin, end); 
}

void	mergeInsertionSort( std::list<int> & lst )
{
	PmergeIt<std::list<int>::iterator>	begin(lst.begin(), 1);
	PmergeIt<std::list<int>::iterator>	end(lst.end(), 1);
	mergeInsertionSort(begin, end); 
}

#endif // PMERGEME_HPP
