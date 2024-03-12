#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{

private:

public:

	WrongCat( void );
	WrongCat( WrongCat const & src );
	~WrongCat( void );
	WrongCat & operator=( WrongCat const & other );

	void	makeSound( void ) const;

};

#endif // WRONGCAT_HPP
