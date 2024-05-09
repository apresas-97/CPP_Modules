#include "FlagTrap.hpp"

FlagTrap::FlagTrap( void ) : ClapTrap( "Default", 100, 100, 30)
{
	std::cout << "FlagTrap " << this->_name << " was constructed" << std::endl;
}

FlagTrap::FlagTrap( std::string name ) : ClapTrap( name, 100, 100, 30 )
{
	std::cout << "FlagTrap " << this->_name << " was constructed" << std::endl;
}

FlagTrap::FlagTrap( FlagTrap const & src ) : ClapTrap( src )
{
	*this = src;
	std::cout << "FlagTrap " << this->_name << " was copy constructed" << std::endl;
}

FlagTrap::~FlagTrap( void )
{
	std::cout << "FlagTrap " << this->_name << " was destroyed" << std::endl;
}

FlagTrap &	FlagTrap::operator=( FlagTrap const & other )
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

void	FlagTrap::highFiveGuys( void ) const
{
	if (this->_hitPoints == 0)
		std::cout << "FlagTrap " << this->_name << " would want to do a high five, but he has ho hit points left!" << std::endl;
	else
		std::cout << "FlagTrap " << this->_name << " wants to do a high five!" << std::endl;
}
