#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{

public:

	HumanB( void );
	HumanB( std::string name );
	~HumanB( void );

	const std::string& getName( void ) const;
	void	attack( void ) const ;
	void	setWeapon( Weapon& weapon );

private:

	Weapon		*_weapon;
	std::string	_name;

};


#endif