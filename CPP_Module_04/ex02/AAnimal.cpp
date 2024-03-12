#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : type("typeless")
{
	std::cout << "Animal default constructed" << std::endl;
}

AAnimal::AAnimal( AAnimal const & src )
{
	std::cout << "Animal copy constructed" << std::endl;
	*this = src;
}

AAnimal::~AAnimal( void )
{
	std::cout << "Animal destroyed" << std::endl;
}

AAnimal &	AAnimal::operator=( AAnimal const & other )
{
	if ( this != &other )
		this->type = other.type;
	return *this;
}

void	AAnimal::makeSound( void ) const
{
	std::cout << "Animal: Generic noises" << std::endl;
}

std::string	AAnimal::getType( void ) const
{
	return (this->type);
}
