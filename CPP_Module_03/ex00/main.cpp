#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap a("Aparatus");
	ClapTrap b("Robotijo");
	ClapTrap c(a);
	ClapTrap d = b;

	std::cout << "-----" << std::endl;

	b.displayStats();
	b.attack("Aparatus");
	b.attack("Aparatus");
	b.attack("Aparatus");
	b.displayStats();

	std::cout << "-----" << std::endl;

	b.takeDamage(9);
	b.displayStats();
	b.beRepaired(9);
	b.displayStats();

	std::cout << "-----" << std::endl;

	b.attack("Aparatus");
	b.attack("Aparatus");
	b.attack("Aparatus");
	b.attack("Aparatus");
	b.attack("Aparatus");
	b.attack("Aparatus");
	b.displayStats();
	b.attack("Aparatus");
	b.beRepaired(10);
	b.takeDamage(5);
	b.displayStats();

	std::cout << "-----" << std::endl;

	a.displayStats();
	a.takeDamage(9);
	a.displayStats();
	a.takeDamage(1);
	a.displayStats();
	a.attack("Somebody");
	a.beRepaired(5);
	a.takeDamage(5);

	std::cout << "-----" << std::endl;

	return 0;
}
