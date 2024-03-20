#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{

public:

	Ice( void );
	Ice( Ice const & src );
	Ice & operator=( Ice const & other );
	~Ice( void );

	virtual AMateria*	clone( void ) const;
	void				use( ICharacter & target );

};

#endif // ICE_HPP
