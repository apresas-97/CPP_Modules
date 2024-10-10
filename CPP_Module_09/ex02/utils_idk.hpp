#ifndef UTILS_IDK_HPP
#define UTILS_IDK_HPP

#include <vector>
#include <list>
#include <iostream>
#include <typeinfo>


template<typename Iterator>
std::vector<std::pair<int, int> >	makePairVector( Iterator begin, Iterator end )
{
	// typedef typename std::iterator_traits<Iterator>::value_type valueType;
	std::vector<std::pair<int, int> >	pairs;
	Iterator	it = begin;

	size_t	nbPairs = (end - begin) / 2;
	for (size_t i = 0; i < nbPairs; i++)
	{
		// if (typeid(valueType) == typeid(int))
		// 	pairs.push_back(std::make_pair(*it, *(it + 1)));
		// else if (typeid(valueType) == typeid(std::pair<int, int>))
			pairs.push_back(std::make_pair(it->first, (it + 1)->first));
		it += 2;
	}
	return pairs;
}

template<>
std::vector<std::pair<int, int> >	makePairVector( std::vector<int>::iterator begin, std::vector<int>::iterator end )
{
	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>::iterator			it = begin;

	size_t	nbPairs = (end - begin) / 2;
	for (size_t i = 0; i < nbPairs; i++)
	{
		pairs.push_back(std::make_pair(*it, *(it + 1)));
		// std::cout << "Pair: " << *it << " " << *(it + 1) << std::endl;
		it += 2;
	}
	return pairs;
}

// template<typename Iterator>
// std::list<std::pair<int, int> >	makePairList( Iterator begin, Iterator end )
// {
// 	// typedef typename std::iterator_traits<Iterator>::value_type valueType;
// 	// if (typeid(Iterator) == typeid(std::list<int>::iterator) || typeid(Iterator) == typeid(std::list<std::pair<int, int> >::iterator))
// 	// 	std::list<std::pair<int, int> >	pairs;
// 	// else if (typeid(Iterator) == typeid(std::vector<int>::iterator) || typeid(Iterator) == typeid(std::vector<std::pair<int, int> >::iterator))
// 	// 	std::vector<std::pair<int, int> >	pairs;
// 	// else
// 	// 	throw std::exception();

// 	std::list<std::pair<int, int> >	pairs;
// 	std::list<int>::const_iterator	it = list.begin();

// 	size_t	nbPairs = (end - begin) / 2;
// 	for (size_t i = 0; i < nbPairs; i++)
// 	{
// 		if (typeid(valueType) == typeid(int))
// 			pairs.push_back(std::make_pair(*it, *(++it)));
// 		else if (typeid(valueType) == typeid(std::pair<int, int>))
// 			pairs.push_back(std::make_pair(it->first, (++it)->first));
// 	}
// 	return pairs;
// }

#endif // UTILS_IDK_HPP