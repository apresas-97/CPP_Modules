#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	std::cout << "Creating ScavTrap:\n" << std::endl;

	ScavTrap a("SCAV");
	a.displayStats();
	a.attack("Monster");
	a.takeDamage(25);
	a.beRepaired(25);
	a.guardGate();
	a.displayStats();

	// if (false) // Comment this if you want to test the copy constructor
	{
		std::cout << "\n--------" << std::endl;
		std::cout << "Testing ScavTrap Copy constructor:\n" << std::endl;

		ScavTrap b(a);
		b.displayStats();
	}

	std::cout << "\n--------" << std::endl;
	std::cout << "Checking ScavTrap behavior when out of hit points:\n" << std::endl;

	a.takeDamage(100);
	a.beRepaired(100);
	a.guardGate();
	a.displayStats();

	// if (false) // Comment this if you want to test the ClapTrap class
	{
		std::cout << "\n--------" << std::endl;
		std::cout << "Creating ClapTrap:\n" << std::endl;
		
		ClapTrap clap("CLAP");
		clap.displayStats();
	}

	std::cout << "\n--------" << std::endl;
	return 0;
}
