#include "Contact.hpp"

int Contact::_contactCount = 0;

Contact::Contact()
{

}

Contact::~Contact()
{

}

void	Contact::setFirstName(std::string str)
{
	this->firstName = str;
}

void	Contact::setLastName(std::string str)
{
	this->lastName = str;
}

void	Contact::setNickname(std::string str)
{
	this->nickname = str;
}

void	Contact::setPhoneNumber(std::string str)
{
	this->phoneNumber = str;
}

void	Contact::setDarkestSecret(std::string str)
{
	this->darkestSecret = str;
}

std::string	Contact::getFirstName() const
{
	return (this->firstName);
}
std::string	Contact::getLastName() const
{
	return (this->lastName);
}
std::string	Contact::getNickname() const
{
	return (this->nickname);
}
std::string	Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}
std::string	Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}
