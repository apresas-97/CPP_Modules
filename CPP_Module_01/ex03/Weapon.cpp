#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->type = type;
	std::cout << "<Weapon " << type << " created>" << std::endl;
}

Weapon::Weapon( void )
{
	this->type = "(null)";
	std::cout << "<Weapon " << type << " created>" << std::endl;
}

Weapon::~Weapon( void )
{
	std::cout << "<Weapon " << type << " destroyed>" << std::endl;
}

const std::string&	Weapon::getType( void ) const
{
	return (this->type);
}

void	Weapon::setType( std::string type )
{
	this->type = type;
}
