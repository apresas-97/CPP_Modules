#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
	// std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice( Ice & src ) : AMateria(src)
{
	// std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
}

Ice::~Ice( void )
{
	// std::cout << "Ice destructor called" << std::endl;
}

Ice &	Ice::operator=( Ice const & other )
{
	// std::cout << "Ice assignment operator called" << std::endl;
	if ( this != &other )
	{
		
	}
	return *this;
}

AMateria*	Ice::clone( void ) const
{

}

void	Ice::use( ICharacter & target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
