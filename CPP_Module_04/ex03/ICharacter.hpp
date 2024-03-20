#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria;

class ICharacter
{

protected:

	// ICharacter( void );
	// ICharacter( ICharacter const & src );
	// ICharacter & operator=( ICharacter const & other );

public:

	virtual ~ICharacter( void ) {}

	virtual std::string const &	getName( void ) const = 0;
	virtual void				equip( AMateria* m ) = 0;
	virtual void				unequip( int idx ) = 0;
	virtual void				use( int idx, ICharacter & target ) = 0;
	virtual AMateria*			getDroppedMaterias( void ) = 0;

};

#endif // ICHARACTER_HPP
