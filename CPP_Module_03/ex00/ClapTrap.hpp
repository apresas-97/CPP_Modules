#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{

private:

	std::string const	_name;
	unsigned int		_hitPoints;
	unsigned int		_energyPoints;
	unsigned int const	_attackDamage;

public:

	ClapTrap( void );
	ClapTrap( std::string const name );
	ClapTrap( ClapTrap const & src );
	~ClapTrap( void );

	ClapTrap & operator=( ClapTrap const & rhs );

	void	attack( std::string const & target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
	void	displayHitPoints( void ) const;
	void	displayEnergyPoints( void ) const;
	void	displayStats( void ) const;

};

#endif // CLAPTRAP_HPP
