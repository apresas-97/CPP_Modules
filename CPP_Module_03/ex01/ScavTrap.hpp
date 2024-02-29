#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:

	ScavTrap( void );
	ScavTrap( std::string const val );
	ScavTrap( ScavTrap const & src );
	~ScavTrap( void );

	ScavTrap & operator=( ScavTrap const & other );

	void	attack( std::string target );
	void	guardGate( void ) const;

};

#endif // SCAVTRAP_HPP
