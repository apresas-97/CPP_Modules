#include "Cure.hpp"

Cure::Cure( void )
{
	// std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure( Cure & src )
{
	// std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure &	Cure::operator=( Cure const & other )
{
	// std::cout << "Cure assignment operator called" << std::endl;
	if ( this != &other )
	{
		
	}
	return *this;
}

Cure::~Cure( void )
{
	// std::cout << "Cure destructor called" << std::endl;
}
