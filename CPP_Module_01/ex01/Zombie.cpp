#include "Zombie.hpp"

Zombie::Zombie( void )
{
	this->_name = "Nameless";
	std::cout << this->_name << " was created" << std::endl;
}

Zombie::Zombie( std::string name )
{
	this->_name = name;
	std::cout << this->_name << " was created" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << this->_name << " was destroyed" << std::endl;
}

void	Zombie::announce( void ) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName( std::string name )
{
	std::cout << this->_name << " was renamed to " << name << std::endl;
	this->_name = name;
}
