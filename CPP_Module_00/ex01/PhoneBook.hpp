#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
	
public:

	PhoneBook();
	~PhoneBook();

	void		add();
	void		search();

	void		displayContact( int index );
	std::string fixTextForDisplay( std::string text );
	std::string	getUserInput( std::string prompt );
	int			verifyPhoneNumber( std::string phoneNumer );
	int			maxContactsReached( void );

private:

	Contact contact[8];
	int	contactIndex;
	int	contactCount;

};

#endif