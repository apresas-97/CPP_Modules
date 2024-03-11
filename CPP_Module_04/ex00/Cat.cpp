#include "Cat.hpp"

Cat::Cat( void )
{
	this->type = "Cat";
	std::cout << "Cat default constructed" << std::endl;
}

Cat::Cat( Cat const & src ) : Animal()
{
	std::cout << "Cat copy constructed" << std::endl;
	*this = src;
}

Cat::~Cat( void )
{
	std::cout << "Cat destroyed" << std::endl;
}

Cat &	Cat::operator=( Cat const & other )
{
	if ( this != &other )
		this->type = other.type;
	return *this;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Cat: Meowwwwww" << std::endl;
}
