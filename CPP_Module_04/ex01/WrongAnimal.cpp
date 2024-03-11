#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("typeless")
{
	std::cout << "WrongAnimal default constructed" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src )
{
	std::cout << "WrongAnimal copy constructed" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal destroyed" << std::endl;
}

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & other )
{
	if ( this != &other )
		this->type = other.type;
	return *this;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal: Generic noises" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}
