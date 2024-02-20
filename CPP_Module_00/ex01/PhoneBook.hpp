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

	void		displayContact( int index ) const;
	std::string fixTextForDisplay( std::string text ) const;
	std::string	getUserInput( std::string prompt ) const;
	int			verifyPhoneNumber( std::string phoneNumer ) const;
	int			maxContactsReached( void ) const;

private:

	Contact contact[8];
	int	contactIndex;
	int	contactCount;

};

#endif