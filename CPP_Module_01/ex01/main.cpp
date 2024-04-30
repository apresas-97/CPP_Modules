#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name );

int	main(void)
{
	int count = 5;

	std::cout << "// Creating a horde of " << count << " zombies named Carlos:" << std::endl;
	Zombie	*horde = zombieHorde(count, "Carlos");

	std::cout << "// Announcing the horde:" << std::endl;
	for (int i = 0; i < count; i++)
		horde[i].announce();

	std::cout << "// Deleting the horde:" << std::endl;
	delete [] (horde);

	std::cout << "// Exiting the program" << std::endl;
	return (0);
}
