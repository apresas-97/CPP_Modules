#include "Character.hpp"

Character::Character( void ) : _name("Default")
{
	std::cout << "Character constructor called" << std::endl;
	this->_initialiseInventory();
	this->_dropped = NULL;
}

Character::Character( std::string name ) : _name(name)
{
	std::cout << "Character parameterized constructor called" << std::endl;
	this->_initialiseInventory();
	this->_dropped = NULL;
}

Character::Character( Character & src )
{
	std::cout << "Character copy constructor called" << std::endl;
	this->_initialiseInventory();
	this->_name = src._name + "Copy";
	*this = src;
}

Character::~Character( void )
{
	std::cout << "Character destructor called" << std::endl;
	this->_deleteInventory();
}

Character &	Character::operator=( Character const & other )
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_deleteInventory();
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
			{
				this->_inventory[i] = other._inventory[i]->clone();
				this->_inventory[i]->setOwner(*this);
			}
		}
	}
	return *this;
}

void	Character::_initialiseInventory( void )
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_dropped = NULL;
}

void	Character::_deleteInventory( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	if (this->_dropped && this->_dropped->isOwned() == false)
		delete this->_dropped;
	this->_dropped = NULL;
}

std::string const &	Character::getName( void ) const
{
	return this->_name;
}

void	Character::equip( AMateria* m )
{
	if (!m)
	{
		std::cout << "Character " << this->_name << " cannot equip the materia because it doesn't exist" << std::endl;
		return ;
	}
	for (int i = 0; i <= 3; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			if (m->setOwner(*this) == false)
				std::cout << "Character " << this->_name << " cannot equip the materia because it's owned by " << m->getOwner() << std::endl;
			else
			{
				this->_inventory[i] = m;
				std::cout << "Character " << this->_name << " equipped a " << m->getType() << " materia" << std::endl;
			}
			return ;
		}
	}
	std::cout << "Character " << this->_name << " cannot equip the materia because its inventory is full" << std::endl;
}

void	Character::unequip( int idx )
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Character " << this->_name << " cannot unequip, index is out of bounds" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "Character " << this->_name << " cannot unequip, slot is empty" << std::endl;
		return ;
	}
	if (this->_dropped)
	{
		std::cout << "Character " << this->_name << " cannot unequip yet, you must pick up the previously dropped Materia to prevent leaks" << std::endl;
		return ;
	}
	this->_dropped = this->_inventory[idx];
	this->_dropped->disown(); // Remove ownership from the item
	this->_inventory[idx] = NULL;
	std::cout << "Character " << this->_name << " unequipped a materia of type " << this->_dropped->getType() << std::endl;
}

void	Character::use(int idx, ICharacter & target )
{
	// std::cout << "Character " << this->_name << " will use a materia on " << target.getName() << std::endl;
	if (idx > 3 || idx < 0)
	{
		std::cout << "Character "  << this->_name << " cannot use anything, the index " << idx << " is out of bounds" << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "Character "  << this->_name << " has nothing to use in the inventory slot " << idx << "!" << std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
}

AMateria*	Character::getDroppedMaterias( void )
{
	AMateria* droppedMateria = this->_dropped;
	this->_dropped = NULL;
	return droppedMateria;
}
