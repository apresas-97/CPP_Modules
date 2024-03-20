#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
	this->_owned = 0;
}

Cure::Cure( Cure const & src ) : AMateria(src)
{
	std::cout << "Cure copy constructor called" << std::endl;
	this->_owned = 0;
	*this = src;
}

Cure::~Cure( void )
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure &	Cure::operator=( Cure const & other )
{
	std::cout << "Cure assignment operator called" << std::endl;
	if ( this != &other )
	{
		this->_type = other._type;
	}
	return *this;
}

AMateria*	Cure::clone( void ) const
{
	AMateria*	clone = new Cure(*this);
	return clone;
}

void	Cure::use( ICharacter & target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
