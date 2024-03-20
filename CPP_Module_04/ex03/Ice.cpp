#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
	this->_owned = 0;
}

Ice::Ice( Ice const & src ) : AMateria(src)
{
	std::cout << "Ice copy constructor called" << std::endl;
	this->_owned = 0;
	*this = src;
}

Ice::~Ice( void )
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice &	Ice::operator=( Ice const & other )
{
	std::cout << "Ice assignment operator called" << std::endl;
	if ( this != &other )
	{
		this->_type = other._type;
	}
	return *this;
}

AMateria*	Ice::clone( void ) const
{
	AMateria*	clone = new Ice(*this);
	return clone;
}

void	Ice::use( ICharacter & target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
