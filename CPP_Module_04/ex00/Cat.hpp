#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{

private:

public:

	Cat( void );
	Cat( Cat const & src );
	~Cat( void );
	Cat & operator=( Cat const & other );

	virtual void	makeSound( void ) const;

};

#endif // CAT_HPP
