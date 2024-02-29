#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap a("Cachibache");

	a.attack("Monster");
	a.takeDamage(25);
	a.beRepaired(25);
	a.guardGate();

	std::cout << "--------" << std::endl;

	a.takeDamage(100);
	a.beRepaired(100);
	a.guardGate();

	return 0;
}
