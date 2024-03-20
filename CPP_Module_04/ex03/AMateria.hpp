#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{

protected:

	std::string	_type;
	std::string	_owner;
	bool		_owned;

	AMateria( void );
	AMateria( AMateria const & src );
	AMateria( std::string const & type );

public:

	virtual ~AMateria( void );
	AMateria & operator=( AMateria const & other );

	std::string const &	getType( void ) const;
	std::string const &	getOwner( void ) const;
	bool				isOwned( void ) const;
	void				disown( void );
	bool				setOwner( ICharacter & owner );
	bool				setOwner( std::string const & owner );
	virtual AMateria*	clone( void ) const = 0;
	virtual void		use( ICharacter & target );

};

#endif // AMATERIA_HPP
