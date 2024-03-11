#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{

private:


public:

	FlagTrap( void );
	FlagTrap( std::string const val );
	FlagTrap( FlagTrap const & src );
	~FlagTrap( void );

	FlagTrap & operator=( FlagTrap const & other );

	void	highFiveGuys( void ) const;

};

#endif // FLAGTRAP_HPP
