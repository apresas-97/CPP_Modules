#include "Zombie.hpp"

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

int main(void)
{
	Zombie *zombie = newZombie("Victor");
	zombie->announce();
	randomChump("Ivan");
	delete (zombie);
	return (0);
}
