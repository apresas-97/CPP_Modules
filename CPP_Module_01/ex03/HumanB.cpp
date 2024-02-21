#include "HumanB.hpp"

HumanB::HumanB( void )
{
	this->_name = "(null)";
	this->_weapon = NULL;
	std::cout << "<HumanB " << this->_name << " created>" << std::endl;
}

HumanB::HumanB( std::string name ) : _name(name)
{
	std::cout << "<HumanB " << this->_name << " created>" << std::endl;
}

HumanB::~HumanB( void )
{
	std::cout << "<HumanB " << this->_name << " destroyed>" << std::endl;
}

const std::string&	HumanB::getName( void ) const
{
	return (this->_name);
}

void HumanB::attack( void ) const
{
	std::cout << this->getName() << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
}
