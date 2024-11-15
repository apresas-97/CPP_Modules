#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

private:


public:

	FragTrap( void );
	FragTrap( std::string const val );
	FragTrap( FragTrap const & src );
	~FragTrap( void );

	FragTrap & operator=( FragTrap const & other );

	void	highFiveGuys( void ) const;

};

#endif // FRAGTRAP_HPP
