#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	std::cout << "ScavTrap " << this->_name << " was constructed" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	std::cout << "ScavTrap " << this->_name << " was constructed" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap( src )
{
	*this = src;
	std::cout << "ScavTrap " << this->_name << " was copy constructed" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap " << this->_name << " was destroyed" << std::endl;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & other )
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

void	ScavTrap::attack( std::string target )
{
	if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " tried to attack " << target << ", but has no hit points left!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " tried to attack " << target << ", but has no energy points left!" << std::endl;
	else
	{
		this->_energyPoints -= 1;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate( void ) const
{
	if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " tried to get in Gate keeper mode, but has 0 hit points!" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
