#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{

public:

	PhoneBook();
	~PhoneBook();

	void		add();
	void		search() const;


private:

	void		_displayContact( int index ) const;
	std::string _fixTextForDisplay( std::string text ) const;
	std::string	_getUserInput( std::string prompt ) const;
	int			_verifyPhoneNumber( std::string phoneNumer ) const;
	int			_maxContactsReached( void ) const;

	Contact _contact[8];
	int	_contactIndex;
	int	_contactCount;

};

#endif