#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{

private:

	std::string	_name;
	AMateria*	_inventory[4];

protected:

public:

	Character( void );
	Character( Character & src );
	Character & operator=( Character const & other );
	~Character( void );

	virtual std::string const &	getName( void ) const;
	virtual void				equip( AMateria* m );
	virtual void				unequip( int idx );
	virtual void				use( int idx, ICharacter & target );

};

#endif // CHARACTER_HPP