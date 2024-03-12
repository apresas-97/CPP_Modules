#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal
{

private:

	Brain*	brain;

public:

	Cat( void );
	Cat( Cat const & src );
	~Cat( void );
	Cat & operator=( Cat const & other );

	virtual void	makeSound( void ) const;
	void			addIdea( std::string idea );
	void			changeIdea( int index, std::string idea );
	std::string		getIdea( int index );

};

#endif // CAT_HPP
