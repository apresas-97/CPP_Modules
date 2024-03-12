#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
{

private:
	Brain*	brain;

public:

	Dog( void );
	Dog( Dog const & src );
	~Dog( void );
	Dog & operator=( Dog const & other );

	virtual void	makeSound( void ) const;
	void			addIdea( std::string idea );
	void			changeIdea( int index, std::string idea );
	std::string		getIdea( int index );

};

#endif // DOG_HPP
