#include "PmergeMe.hpp"

void	PmergeMe::mergeIteratorToContainer( LIterator<uint_t> start, LIterator<uint_t> end, std::list<unsigned int>::iterator lstart )
{
	std::list<uint_t>	cache;
	for (LIterator<uint_t> it = start; it != end; it++)
	{
		std::list<uint_t>::iterator begin = it.base();
		std::list<uint_t>::iterator end = begin;
		std::advance(end, it.size());
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), lstart);
}

void	PmergeMe::mergeIteratorToContainer( VIterator start, VIterator end, std::vector<unsigned int>::iterator vstart )
{
	std::vector<unsigned int>	cache;
	cache.reserve(end - start);
	for (VIterator it = start; it != end; it++)
	{
		std::vector<unsigned int>::iterator begin = it.base();
		std::vector<unsigned int>::iterator end = begin + it.size();
		while (begin != end)
		{
			cache.push_back(*begin);
			begin++;
		}
	}
	std::swap_ranges(cache.begin(), cache.end(), vstart);
}
