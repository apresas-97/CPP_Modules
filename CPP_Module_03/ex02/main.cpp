#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	std::cout << "Creating FragTrap:\n" << std::endl;

	FragTrap a("FRAG");
	a.displayStats();
	a.attack("Monster");
	a.takeDamage(25);
	a.beRepaired(25);
	a.highFiveGuys();

	// if (false) // Comment this if you want to test the copy constructor
	{
		std::cout << "\n--------" << std::endl;
		std::cout << "Testing FragTrap Copy constructor:\n" << std::endl;

		FragTrap b(a);
		b.displayStats();
	}

	std::cout << "\n--------" << std::endl;
	std::cout << "Checking FragTrap behavior when out of hit points:\n" << std::endl;

	a.takeDamage(100);
	a.beRepaired(100);
	a.highFiveGuys();

	// if (false) // Comment this if you want to test the other classes
	{
		std::cout << "\n--------" << std::endl;
		std::cout << "Creating ClapTrap:\n" << std::endl;

		ClapTrap clap("CLAP");
		clap.displayStats();

		std::cout << "\n--------" << std::endl;
		std::cout << "Creating ScavTrap:\n" << std::endl;

		ScavTrap scav("SCAV");
		scav.displayStats();
	}

	std::cout << "\n--------" << std::endl;
	return 0;
}
