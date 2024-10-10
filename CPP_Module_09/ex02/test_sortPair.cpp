#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

// Sort pair
template <typename T1, typename T2, typename Compare>
inline void sortPair(std::pair<T1, T2>& p, Compare comp)
{
	if (comp(p.second, p.first))
		std::swap(p.first, p.second);
}

template <typename T1, typename T2>
inline void sortPair(std::pair<T1, T2>& p)
{
	if (p.second < p.first)
		std::swap(p.first, p.second);
}

int	main( int argc, char **argv )
{
	if (argc == 1 || argc % 2 == 0)
		return 0;

	size_t	pairs_size = (argc - 1) * (argc - 1);
	std::pair<int, int>	*pairs = new std::pair<int, int>[pairs_size];
	size_t	k = 0;
	for (size_t i = 1; i < argc; i++)
	{
		if (k >= pairs_size)
			break;
		for (size_t j = 1; j < argc; j++)
		{
			pairs[k].first = std::atoi(argv[i]);
			pairs[k].second = std::atoi(argv[j]);
			k++;
		}
	}
	for (size_t i = 0; i < pairs_size; i++)
	{
		sortPair(pairs[i]);
		sortPair<int, int>(pairs[i], std::greater<int>());
		sortPair<int, int>(pairs[i], std::less<int>());
		sortPair<int, int>(pairs[i], std::greater<int>());
		sortPair(pairs[i]);
		sortPair<int, int>(pairs[i], std::greater<int>());
		sortPair<int, int>(pairs[i], std::less<int>());
		sortPair<int, int>(pairs[i], std::greater<int>());
		sortPair(pairs[i]);
		sortPair<int, int>(pairs[i], std::greater<int>());
		sortPair<int, int>(pairs[i], std::less<int>());
		sortPair<int, int>(pairs[i], std::greater<int>());
		sortPair(pairs[i]);
		sortPair<int, int>(pairs[i], std::greater<int>());
		sortPair<int, int>(pairs[i], std::less<int>());
		sortPair<int, int>(pairs[i], std::greater<int>());
	}

	delete [] pairs;
	return 0;
}