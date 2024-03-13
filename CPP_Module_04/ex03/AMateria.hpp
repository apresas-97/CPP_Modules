#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>

class AMateria
{
	protected:

		std::string _type;

	public:

	AMateria( void ); // Is not used, but I'm making it canonical orthodox
	AMateria( std::string const & type );
	~AMateria( void );
	AMateria & operator=( AMateria const & other);

	std::string const &	getType( void ) const; //Returns the materia type
	virtual AMateria*	clone( void ) const = 0;
	// This one is a PURE VIRTUAL class, which means that
	// AMateria does not have a definition for this, it must be
	// given by each derived class

	virtual void		use( ICharacter& target );
	/* This function recieves a ICharacter interface so that any
	class that is sent here that inherits from that Interface will be able
	to be used.
	Inside use, we would use something like
	target->someFunction();
	In this case, someFunction(); will be a function from the ICharacter class
	By using ICharacter, we ensure that any class sent here, can use the
	functions want them to use. (As I said, as long as it inherited from ICharacter)*/

};

#endif // AMATERIA_HPP
