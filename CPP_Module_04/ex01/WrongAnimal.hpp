#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{

private:

protected:

	std::string type;

public:

	WrongAnimal( void );
	WrongAnimal( WrongAnimal const & src );
	virtual ~WrongAnimal( void );
	WrongAnimal & operator=( WrongAnimal const & other );

	void	makeSound( void ) const;
	std::string		getType( void ) const;

};

#endif // WRONGANIMAL_HPP
