#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int	main( void )
{
	FlagTrap a("Flaggy");

	a.attack("Monster");
	a.takeDamage(25);
	a.beRepaired(25);
	a.highFiveGuys();

	std::cout << "--------" << std::endl;

	a.takeDamage(100);
	a.beRepaired(100);
	a.highFiveGuys();

	return 0;
}
