#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{

private:

protected:

	std::string type;

public:

	Animal( void );
	Animal( Animal const & src );
	virtual ~Animal( void );
	Animal & operator=( Animal const & other );

	virtual void	makeSound( void ) const;
	std::string		getType( void ) const;

};

#endif // ANIMAL_HPP
