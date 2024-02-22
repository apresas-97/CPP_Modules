#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{

public:

	Weapon( void );
	Weapon( std::string type );
	~Weapon( void );

	const std::string&	getType() const;
	void				setType( std::string type );

private:

	std::string type;

};




#endif