#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap a("Diamondy");

	std::cout << "Attack:" << std::endl;
	a.attack("Monster");
	std::cout << "--------" << std::endl;
	std::cout << "Take damage:" << std::endl; 
	a.takeDamage(25);
	std::cout << "--------" << std::endl;
	std::cout << "Be repaired:" << std::endl; 
	a.beRepaired(25);
	std::cout << "--------" << std::endl;
	std::cout << "Take 100 damage:" << std::endl; 
	a.takeDamage(100);
	std::cout << "--------" << std::endl;
	std::cout << "Try to be repaired:" << std::endl; 
	a.beRepaired(100);
	std::cout << "--------" << std::endl;
	std::cout << "WhoAmI:" << std::endl;
	a.whoAmI(); 
	std::cout << "--------" << std::endl;
	std::cout << "Try to attack:" << std::endl;
	a.attack("Monster");

	return 0;
}
