#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{

private:

protected:

public:

	Ice( void );
	Ice( Ice & src );
	Ice & operator=( Ice const & other );
	~Ice( void );

	virtual AMateria*	clone( void ) const = 0;
	void				use( ICharacter & target );

};

#endif // ICE_HPP