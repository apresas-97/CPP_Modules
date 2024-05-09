#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap()
{
	this->_name = ClapTrap::_name;
	ClapTrap::_name += "_clap_name";
	std::cout << "DiamondTrap " << this->_name << " was constructed" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_name" )
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " was constructed" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap( src ), ScavTrap( src ), FragTrap( src )
{
	*this = src;
	std::cout << "DiamondTrap " << this->_name << " was copy constructed" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap " << this->_name << " was destroyed" << std::endl;
}

DiamondTrap &	DiamondTrap::operator=( DiamondTrap const & other )
{
	if ( this != &other )
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void	DiamondTrap::whoAmI( void ) const
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
