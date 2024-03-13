#include "AMateria.hpp"

AMateria::AMateria( void )
{

}

AMateria::AMateria( std::string const & type ) : _type(type)
{

}

AMateria::~AMateria( void )
{

}

AMateria &	AMateria::operator=( AMateria const & other )
{
	if ( this != &other )
	{
		this->_type = other._type;
	}
	return *this;
}

std::string	const & AMateria::getType( void ) const
{
	return (this->_type);
}



AMateria*	AMateria::clone( void ) const
{

}

void	AMateria::use( ICharacter & target );
{

}
