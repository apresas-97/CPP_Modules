#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap( "Default", 100, 100, 30)
{
	std::cout << "FragTrap " << this->_name << " was constructed" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name, 100, 100, 30 )
{
	std::cout << "FragTrap " << this->_name << " was constructed" << std::endl;
}

FragTrap::FragTrap( FragTrap const & src ) : ClapTrap( src )
{
	*this = src;
	std::cout << "FragTrap " << this->_name << " was copy constructed" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap " << this->_name << " was destroyed" << std::endl;
}

FragTrap &	FragTrap::operator=( FragTrap const & other )
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

void	FragTrap::highFiveGuys( void ) const
{
	if (this->_hitPoints == 0)
		std::cout << "FragTrap " << this->_name << " would want to do a high five, but he has ho hit points left!" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " wants to do a high five!" << std::endl;
}
