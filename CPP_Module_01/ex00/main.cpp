#include "Zombie.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define CYAN "\033[36m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

int main(void)
{
	std::cout << GREEN "\nZombie " BLUE "*zombie" RESET " = " ITALIC CYAN "newZombie(" RESET "\"Victor\"" ITALIC CYAN ")" RESET ";" << std::endl;
	Zombie *zombie = newZombie("Victor");
	std::cout << BLUE "\nzombie" RESET "->" ITALIC CYAN "announce()" RESET ";" << std::endl;
	zombie->announce();
	std::cout << ITALIC CYAN "\nrandomChump(" RESET "\"Ivan\"" ITALIC CYAN ")" RESET ";" << std::endl;
	randomChump("Ivan");
	std::cout << MAGENTA "\ndelete (" RESET "zombie" MAGENTA ")" RESET ";" << std::endl;
	delete (zombie);
	std::cout << MAGENTA "\nreturn (" RESET "0" MAGENTA ")" RESET ";" << std::endl;
	return (0);
}
