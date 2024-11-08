#include "PmergeMe.hpp"

void	PmergeMe::timeStart( int type )
{
	this->_time_start[type] = std::clock();
}

void	PmergeMe::timeEnd( int type )
{
	this->_time_elapsed[type] = (double)(std::clock() - this->_time_start[type]) / CLOCKS_PER_SEC;
	this->_time_set[type] = true;
}

void	PmergeMe::setTimeUnit( void )
{
	int	type = LIST;
	if (this->_time_elapsed[VECTOR] > this->_time_elapsed[LIST])
		type = VECTOR;
	if (this->_time_elapsed[type] * 1000 < 1)
	{
		this->_time_unit = "us";
		this->_time_multiplier = 1000000;
	}
	else if (this->_time_elapsed[type] * 1 < 1)
	{
		this->_time_unit = "ms";
		this->_time_multiplier = 1000;
	}
	else
	{
		this->_time_unit = "s";
		this->_time_multiplier = 1;
	}
}

void	PmergeMe::printTimeElapsed( void )
{
	setTimeUnit();
	if (this->_time_set[VECTOR] == true)
	{
		std::cout << "Time to sort " << this->_elements_count[VECTOR] << " elements with std::vector: " << this->_time_elapsed[VECTOR] * this->_time_multiplier << this->_time_unit << std::endl;
		this->_time_elapsed[VECTOR] = 0.0;
		this->_elements_count[VECTOR] = 0;
	}
	else
		std::cout << "Time to sort " << this->_elements_count[VECTOR] << " elements with std::vector:   N/A" << std::endl;

	if (this->_time_set[LIST] == true)
	{
		std::cout << "Time to sort " << this->_elements_count[LIST] << " elements with std::list:   " << this->_time_elapsed[LIST] * this->_time_multiplier << this->_time_unit << std::endl;
		this->_time_elapsed[LIST] = 0.0;
		this->_elements_count[LIST] = 0;
	}
	else
		std::cout << "Time to sort " << this->_elements_count[LIST] << " elements with std::list:   N/A" << std::endl;
}
