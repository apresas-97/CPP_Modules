#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{

public:

	Cure( void );
	Cure( Cure const & src );
	Cure &	operator=( Cure const & other );
	~Cure( void );

	virtual AMateria*	clone( void ) const; // Must be overwritten
	virtual void		use( ICharacter& target ); // ?

};

#endif // CURE_HPP
