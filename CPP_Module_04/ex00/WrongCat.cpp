#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	this->type = "Cat";
	std::cout << "WrongCat default constructed" << std::endl;
}

WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal()
{
	std::cout << "WrongCat copy constructed" << std::endl;
	*this = src;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat &	WrongCat::operator=( WrongCat const & other )
{
	if ( this != &other )
		this->type = other.type;
	return *this;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat: Meowwwwww" << std::endl;
}
