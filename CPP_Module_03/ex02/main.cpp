#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int	main( void )
{
	std::cout << "Creating FlagTrap:\n" << std::endl;

	FlagTrap a("FLAG");
	a.attack("Monster");
	a.takeDamage(25);
	a.beRepaired(25);
	a.highFiveGuys();

	// if (false) // Comment this if you want to test the copy constructor
	{
		std::cout << "\n--------" << std::endl;
		std::cout << "Testing FlagTrap Copy constructor:\n" << std::endl;

		FlagTrap b(a);
		b.attack("Monster");
		b.beRepaired(25);
	}

	std::cout << "\n--------" << std::endl;
	std::cout << "Checking FlagTrap behavior when out of hit points:\n" << std::endl;

	a.takeDamage(100);
	a.beRepaired(100);
	a.highFiveGuys();

	if (false) // Comment this if you want to test the other classes
	{
		std::cout << "\n--------" << std::endl;
		std::cout << "Creating ClapTrap:\n" << std::endl;

		ClapTrap clap("CLAP");
		clap.attack("Monster");

		std::cout << "\n--------" << std::endl;
		std::cout << "Creating ScavTrap:\n" << std::endl;

		ScavTrap scav("SCAV");
		scav.attack("Monster");
	}

	std::cout << "\n--------" << std::endl;
	return 0;
}
