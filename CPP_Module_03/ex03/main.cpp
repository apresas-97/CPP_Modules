#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap a("DIAMOND");
	std::cout << "\n--------\n" << std::endl;

	std::cout << "Stats are mixed from ScavTrap and FragTrap:" << std::endl;
	a.displayStats();

	std::cout << "\nInherits ScavTrap's attack:" << std::endl;
	a.attack("Monster");
	std::cout << "\n--------\n" << std::endl;

	std::cout << "The rest, it inherits from whichever was the original class:" << std::endl;
	std::cout << "-Take damage:" << std::endl; 
	a.takeDamage(10);
	std::cout << "-Guard gate:" << std::endl;
	a.guardGate();
	std::cout << "-High five:" << std::endl;
	a.highFiveGuys();

	std::cout << "\n--------\n" << std::endl;
	std::cout << "WhoAmI:" << std::endl;
	a.whoAmI(); 
	std::cout << "\n--------\n" << std::endl;

	std::cout << "Copy constructor:" << std::endl;
	DiamondTrap b(a);
	std::cout << "--------" << std::endl;
	a.displayStats();
	std::cout << "--------" << std::endl;
	b.displayStats();
	std::cout << "--------\n" << std::endl;

	std::cout << "Assignment operator:" << std::endl;
	DiamondTrap c("DIAMOND_TWO");
	c = a;
	std::cout << "--------" << std::endl;
	a.displayStats();
	std::cout << "--------" << std::endl;	
	c.displayStats();
	std::cout << "--------\n" << std::endl;

	std::cout << "Destructor:" << std::endl;
	return 0;
}
