#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{

private:

	std::string	_name;

public:

	Zombie();
	Zombie( std::string name );
	~Zombie( void );

	void	announce( void ) const;
	void	setName( std::string name );

};

#endif