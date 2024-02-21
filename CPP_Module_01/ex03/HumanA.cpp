#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
	std::cout << "<HumanA " << this->_name << " created>" << std::endl;
}

HumanA::~HumanA( void )
{
	std::cout << "<HumanA " << this->_name << " destroyed>" << std::endl;
}

const std::string&	HumanA::getName( void ) const
{
	return (this->_name);
}

void HumanA::attack( void ) const
{
	std::cout << this->getName() << " attacks with their " << this->_weapon.getType() << std::endl;
}
