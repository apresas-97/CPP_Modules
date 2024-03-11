#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

class DiamondTrap : public ScavTrap, public FlagTrap
{

private:

	std::string	_name;

public:

	DiamondTrap( void );
	DiamondTrap( std::string const name );
	DiamondTrap( DiamondTrap const & src );
	~DiamondTrap( void );

	DiamondTrap & operator=( DiamondTrap const & other );

	void	whoAmI( void ) const;
	using	ScavTrap::attack;

};

#endif // DIAMONDTRAP_HPP
