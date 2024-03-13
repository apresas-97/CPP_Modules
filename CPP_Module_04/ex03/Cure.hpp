#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{

private:

	// It already inherits _type from AMateria

public:

	Cure( void );
	Cure( Cure & src );
	Cure &	operator=( Cure const & other );
	~Cure( void );

	virtual AMateria*	clone( void ) const = 0; // Must be overwritten
	virtual void		use( ICharacter& target ); // ?

};



#endif // CURE_HPP
