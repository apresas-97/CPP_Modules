#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{

private:

public:

	Dog( void );
	Dog( Dog const & src );
	~Dog( void );
	Dog & operator=( Dog const & other );

	virtual void	makeSound( void ) const;

};

#endif // DOG_HPP
