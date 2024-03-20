#include "AMateria.hpp"

AMateria::AMateria( void )
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria( AMateria const & src )
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
	std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::~AMateria( void )
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &	AMateria::operator=( AMateria const & other )
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if ( this != &other )
	{
		// No variable in an AMateria object makes sense to be copied
	}
	return *this;
}

std::string	const & AMateria::getType( void ) const
{
	return this->_type;
}

std::string const & AMateria::getOwner( void ) const
{
	return this->_owner;
}

bool	AMateria::isOwned( void ) const
{
	return this->_owned;
}

bool	AMateria::setOwner( ICharacter & owner )
{
	if (this->_owned == true)
		return false;
	this->_owned = true;
	this->_owner = owner.getName();
	return true;
}

bool	AMateria::setOwner( std::string const & name )
{
	if (this->_owned == true)
		return false;
	this->_owned = true;
	this->_owner = name;
	return true;
}

void	AMateria::disown( void )
{
	this->_owned = false;
	this->_owner = "";
}

void	AMateria::use( ICharacter & target )
{
	std::cout << "* a typeless materia was cast on " << target.getName() << " *" << std::endl;
}
