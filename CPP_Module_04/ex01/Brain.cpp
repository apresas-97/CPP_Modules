#include "Brain.hpp"
#include <iostream>

Brain::Brain( void )
{
	this->_index = 0;
	std::cout << "Brain default constructed" << std::endl;
}

Brain::Brain( Brain const & src )
{
	std::cout << "Brain copy constructed" << std::endl;
	*this = src;
}

Brain::~Brain( void )
{
	this->_index = 0;
	std::cout << "Brain destroyed" << std::endl;
}

Brain &	Brain::operator=( Brain const & other )
{
	std::cout << "Brain operator = called" << std::endl;
	if ( this != &other )
	{
		this->_index = other._index;
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

void	Brain::addIdea( std::string idea )
{
	if (this->_index < 100)
	{
		std::cout << "	Adding new idea to brain->ideas[ " << this->_index << " ]" << std::endl;
		this->ideas[this->_index] = idea;
		this->_index++;
	}
	else
	{
		std::cout << "	Idea cannot be added, brain is at full capacity" << std::endl;
	}
}

void	Brain::changeIdea( int index, std::string idea )
{
	if (index >= 100 || index < 0)
	{
		std::cout << "	Error: Invalid index provided" << std::endl;
		return ;
	}
	std::cout << "	Changing idea in brain->ideas[ " << index << " ]" << std::endl;
	std::cout << "	  Old:	\"" << this->ideas[index] << "\"" << std::endl;
	this->ideas[index] = idea;
	std::cout << "	  New:	\"" << this->ideas[index] << "\"" << std::endl;
}

std::string	Brain::getIdea( int index )
{
	if (index >= 100 || index < 0)
	{
		std::cout << "	Error: Invalid index provided" << std::endl;
		return (NULL);
	}
	return this->ideas[index];
}
