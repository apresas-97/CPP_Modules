#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

private:

	AMateria*	_learnedMaterias[4];

public:

	MateriaSource( void );
	MateriaSource( MateriaSource & src );
	~MateriaSource( void );
	MateriaSource & operator=( MateriaSource const & other );

	void		printMaterias( void ) const;
	void		learnMateria( AMateria* );
	AMateria*	createMateria( std::string const & type );

};

#endif // MATERIASOURCE_HPP
