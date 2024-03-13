#include "Character.hpp"

Character::Character( void ) : _name("Default")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character( Character & src ) : ICharacter(src)
{
	*this = src;
}

Character::~Character( void )
{
	// Debería desalojar los items del inventario o son externos al Character?
}

Character &	Character::operator=( Character const & other )
{

}

std::string const &	Character::getName( void ) const
{
	return this->_name;
}

void	Character::equip( AMateria* m )
{
	if (!m)
	{
		// materia doesn't exist
		// return
	}
	// else implicito
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL) // hueco en el inventario
		{
			
		}
	}
}

void	Character::unequip( int idx )
{

}

void	Character::use(int idx, ICharacter & target )
{
	if (idx >= 0 && idx <= 3 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
