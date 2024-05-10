#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{

protected:
	static unsigned int const _hp;
	static unsigned int const _ep;
	static unsigned int const _ad;

public:

	FragTrap( void );
	FragTrap( std::string const val );
	FragTrap( FragTrap const & src );
	~FragTrap( void );

	FragTrap & operator=( FragTrap const & other );

	void	highFiveGuys( void ) const;

};

#endif // FRAGTRAP_HPP
