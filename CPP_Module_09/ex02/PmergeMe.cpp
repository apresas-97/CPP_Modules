#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{

}

PmergeMe::PmergeMe( PmergeMe const &other )
{
	*this = other;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe &PmergeMe::operator=( PmergeMe const &other )
{
	if ( this != &other )
	{

	}
	return *this;
}

void	mergeInsertionSort( int *array, int size )
{
	int	*temp = new int[size];
	for (int i = 0; i < size; i++)
		temp[i] = array[i];
	std::sort(temp, temp + size);
	for (int i = 0; i < size; i++)
		array[i] = temp[i];
	delete [] temp;
}
