#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

template<typename Iterator, typename Comparator>
void	sortPair( Iterator pairA, Iterator pairB, Comparator comp )
{
	if (comp(*pairB, *pairA))
		std::swap(*pairA, *pairB);
}

int	main( void )
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	std::cout << "Before: " << vec[0] << " " << vec[1] << std::endl;
	sortPair(vec.begin(), vec.end() - 1, std::greater<int>());
	std::cout << "Greater: " << vec[0] << " " << vec[1] << std::endl;
	sortPair(vec.begin(), vec.end() - 1, std::less<int>());
	std::cout << "Less: " << vec[0] << " " << vec[1] << std::endl;
	return 0;
}