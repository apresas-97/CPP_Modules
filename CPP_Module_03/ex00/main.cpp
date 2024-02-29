#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap a("Aparatus");
	ClapTrap b("Robotijo");
	ClapTrap c(a);
	ClapTrap d = b;

	std::cout << "-----" << std::endl;

	b.displayEnergyPoints();
	b.displayHitPoints();
	b.attack("Aparatus");
	b.attack("Aparatus");
	b.attack("Aparatus");
	b.displayEnergyPoints();

	std::cout << "-----" << std::endl;

	b.takeDamage(9);
	b.displayHitPoints();
	b.beRepaired(9);
	b.displayHitPoints();
	b.displayEnergyPoints();

	std::cout << "-----" << std::endl;

	b.attack("Aparatus");
	b.attack("Aparatus");
	b.attack("Aparatus");
	b.attack("Aparatus");
	b.attack("Aparatus");
	b.attack("Aparatus");
	b.displayEnergyPoints();
	b.attack("Aparatus");
	b.beRepaired(10);
	b.takeDamage(5);

	std::cout << "-----" << std::endl;

	a.takeDamage(9);
	a.takeDamage(1);
	a.attack("Somebody");
	a.beRepaired(5);
	a.takeDamage(5);

	std::cout << "-----" << std::endl;

	return 0;
}
