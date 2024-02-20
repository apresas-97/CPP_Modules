#ifndef ZOMBIE_H
# define ZOMBIE_H

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