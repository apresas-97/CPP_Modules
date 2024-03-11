#include "Animal.hpp"

Animal::Animal( void ) : type("typeless")
{
	std::cout << "Animal default constructed" << std::endl;
}

Animal::Animal( Animal const & src )
{
	std::cout << "Animal copy constructed" << std::endl;
	*this = src;
}

Animal::~Animal( void )
{
	std::cout << "Animal destroyed" << std::endl;
}

Animal &	Animal::operator=( Animal const & other )
{
	if ( this != &other )
		this->type = other.type;
	return *this;
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal: Generic noises" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}
