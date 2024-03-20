#ifndef CHARACTER_HPP
# define CHARACTER_HPP


#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{

private:

	std::string				_name;
	AMateria*				_inventory[4];
	AMateria*				_dropped;

	void	_initialiseInventory( void );
	void	_deleteInventory( void );

public:

	Character( void );
	Character( std::string name );
	Character( Character & src );
	Character & operator=( Character const & other );
	~Character( void );

	virtual std::string const &	getName( void ) const;
	virtual void				equip( AMateria* m );
	virtual void				unequip( int idx );
	virtual void				use( int idx, ICharacter & target );
	virtual AMateria*			getDroppedMaterias( void );

};

#endif // CHARACTER_HPP
