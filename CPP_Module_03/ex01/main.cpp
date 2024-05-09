#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	std::cout << "Creating ScavTrap:" << std::endl;

	ScavTrap a("Cachibache");
	a.attack("Monster");
	a.takeDamage(25);
	a.beRepaired(25);
	a.guardGate();

	std::cout << "--------" << std::endl;
	std::cout << "Testing ScavTrap Copy constructor:" << std::endl;

	ScavTrap c(a);
	c.attack("Monster");
	c.beRepaired(25);

	std::cout << "--------" << std::endl;
	std::cout << "Checing ScavTrap behavior when out of hit points:" << std::endl;

	a.takeDamage(100);
	a.beRepaired(100);
	a.guardGate();

	std::cout << "--------" << std::endl;
	std::cout << "Creating ClapTrap:" << std::endl;

	ClapTrap b("Bachibache");
	b.attack("Monster");
	b.takeDamage(10);

	std::cout << "--------" << std::endl;
	return 0;
}
