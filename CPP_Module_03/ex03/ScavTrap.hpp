#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{

protected:
	static unsigned int const _hp;
	static unsigned int const _ep;
	static unsigned int const _ad;

public:

	ScavTrap( void );
	ScavTrap( std::string const val );
	ScavTrap( ScavTrap const & src );
	~ScavTrap( void );

	ScavTrap & operator=( ScavTrap const & other );

	void	attack( std::string const target );
	void	guardGate( void ) const;

};

#endif // SCAVTRAP_HPP
