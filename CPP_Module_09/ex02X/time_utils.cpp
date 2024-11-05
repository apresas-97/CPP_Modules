#include "PmergeMe.hpp"

void	PmergeMe::timeStart( int type )
{
	this->_timeStart[type] = std::clock();
}

void	PmergeMe::timeEnd( int type )
{
	this->_timeElapsed[type] = (double)(std::clock() - this->_timeStart[type]) / CLOCKS_PER_SEC;
}

void	PmergeMe::setTimeUnit( void )
{
	int	type = LIST;
	if (this->_timeElapsed[VECTOR] > this->_timeElapsed[LIST])
		type = VECTOR;
	if (this->_timeElapsed[type] * 1000 < 1)
	{
		this->_timeUnit = "us";
		this->_timeMultiplier = 1000000;
	}
	else if (this->_timeElapsed[type] * 1 < 1)
	{
		this->_timeUnit = "ms";
		this->_timeMultiplier = 1000;
	}
	else
	{
		this->_timeUnit = "s";
		this->_timeMultiplier = 1;
	}
}

void	PmergeMe::printTimeElapsed( void )
{
	setTimeUnit();
	std::cout << "Time to sort " << this->_elementsCount[VECTOR] << " elements with std::vector: " << this->_timeElapsed[VECTOR] * this->_timeMultiplier << this->_timeUnit << std::endl;
	this->_timeElapsed[VECTOR] = 0.0;
	this->_elementsCount[VECTOR] = 0;
	// resetAuxiliary(VECTOR);

	std::cout << "Time to sort " << this->_elementsCount[LIST] << " elements with std::list:   " << this->_timeElapsed[LIST] * this->_timeMultiplier << this->_timeUnit << std::endl;
	this->_timeElapsed[LIST] = 0.0;
	this->_elementsCount[LIST] = 0;
	// resetAuxiliary(LIST);
}