#include "Dog.hpp"

Dog::Dog( void )
{
	this->type = "Dog";
	std::cout << "Dog default constructed" << std::endl;
}

Dog::Dog( Dog const & src ) : Animal()
{
	*this = src;
	std::cout << "Dog copy constructed" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog destroyed" << std::endl;
}

Dog &	Dog::operator=( Dog const & other )
{
	if ( this != &other )
		this->type = other.type;
	return *this;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog: Bark! Bark!" << std::endl;
}
