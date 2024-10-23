#include "PmergeMe.hpp"

void	PmergeMe::printTimeElapsed( void )
{
	std::cout << "Time to sort " << this->_elementsCount[VECTOR] << " elements with std::vector: ";
	if (this->_timeElapsed[VECTOR] * 1000 < 1)
		std::cout << this->_timeElapsed[VECTOR] * 1000000.0 << "us" << std::endl;
	else if (this->_timeElapsed[VECTOR] < 1)
		std::cout << this->_timeElapsed[VECTOR] * 1000.0 << "ms" << std::endl;
	else
		std::cout << this->_timeElapsed[VECTOR] << "s" << std::endl;
	this->_timeElapsed[VECTOR] = 0.0;
	this->_elementsCount[VECTOR] = 0;

	std::cout << "Time to sort " << this->_elementsCount[LIST] << " elements with std::list: ";
	if (this->_timeElapsed[LIST] * 1000 < 1)
		std::cout << this->_timeElapsed[LIST] * 1000000.0 << "us" << std::endl;
	else if (this->_timeElapsed[LIST] < 1)
		std::cout << this->_timeElapsed[LIST] * 1000.0 << "ms" << std::endl;
	else
		std::cout << this->_timeElapsed[LIST] << "s" << std::endl;
	this->_timeElapsed[LIST] = 0.0;
	this->_elementsCount[LIST] = 0;
}
