#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{

private:

protected:

	std::string type;

public:

	AAnimal( void );
	AAnimal( AAnimal const & src );
	virtual ~AAnimal( void );
	AAnimal & operator=( AAnimal const & other );


	virtual void	makeSound( void ) const = 0;
	std::string		getType( void ) const;

};

#endif // AANIMAL_HPP
