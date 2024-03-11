#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name( "Default" ), _hitPoints( 100 ), _energyPoints( 50 ), _attackDamage( 20 )
{
	std::cout << "ClapTrap " << this->_name << " was constructed" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name( name ), _hitPoints( 100 ), _energyPoints( 50 ), _attackDamage( 20 )
{
	std::cout << "ClapTrap " << _name << " was constructed" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src ) : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage)
{
	*this = src;
	std::cout << "ClapTrap " << _name << " was copy constructed" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap " << _name << " was destroyed" << std::endl;
}

ClapTrap &	ClapTrap::operator=( ClapTrap const & other )
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

void	ClapTrap::attack( std::string const & target )
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " tried to attack " << target << ", but has no hit points left!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " tried to attack " << target << ", but has no energy points left!" << std::endl;
	else
	{
		this->_energyPoints -= 1;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't take any more damage!" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage!" << std::endl;
	if (this->_hitPoints > 0 && this->_hitPoints <= amount)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " has reached 0 hit points!" << std::endl;
	}
	else
		this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " tried to repair " << amount << " hit points, but has no hit points left!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " tried to repair " << amount << " hit points, but has no energy points left!" << std::endl;
	else
	{
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " has repaired " << amount << " hit points!" << std::endl;
	}
}

void	ClapTrap::displayHitPoints( void ) const
{
	std::cout << "Claptrap " << this->_name << "'s hit points: " << this->_hitPoints << std::endl;
}

void	ClapTrap::displayEnergyPoints( void ) const
{
	std::cout << "Claptrap " << this->_name << "'s energy points: " << this->_energyPoints << std::endl;
}
