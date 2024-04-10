#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_contactIndex = 0;
	this->_contactCount = 0;
	std::cout << "Welcome to Crappy Awesome Phonebook!" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Crappy Awesome Phonebook is shutting down" << std::endl;
}

std::string	PhoneBook::_getUserInput( std::string prompt ) const
{
	std::string	userInput;
	while (PhoneBook::_isInputEmpty(userInput) && !std::cin.eof())
	{
		std::cout << prompt;
		std::getline(std::cin, userInput);
	}
	return (userInput);
}

//new
int	PhoneBook::_isInputEmpty( std::string input ) const
{
	if (input.empty())
		return 1;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isspace(input[i]))
			return 0;
	}
	return 1;
}

void PhoneBook::add()
{
	std::cout << "Adding a new contact" << std::endl;

	if (PhoneBook::_contactCount >= 8 && PhoneBook::_maxContactsReached() == 1)
		return ;

	std::string firstNameAux = PhoneBook::_getUserInput("First name: ");
	std::string lastNameAux = PhoneBook::_getUserInput("Last name: ");
	std::string nicknameAux = PhoneBook::_getUserInput("Nickname: ");
	std::string phoneNumberAux;
	while (PhoneBook::_verifyPhoneNumber(phoneNumberAux) != 1)
		phoneNumberAux = PhoneBook::_getUserInput("Phone number: ");
	std::string darkestSecretAux = PhoneBook::_getUserInput("Darkest secret: ");

	if (std::cin.eof())
		return ;

	this->_contact[_contactIndex % 8].setFirstName(firstNameAux);
	this->_contact[_contactIndex % 8].setLastName(lastNameAux);
	this->_contact[_contactIndex % 8].setNickname(nicknameAux);
	this->_contact[_contactIndex % 8].setPhoneNumber(phoneNumberAux);
	this->_contact[_contactIndex % 8].setDarkestSecret(darkestSecretAux);

	this->_contactIndex++;
	this->_contactCount++;

	return ;
}

void	PhoneBook::search() const
{
	std::string input;

	std::cout << "Introduce the index of the contact you want to search: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	if (input.size() == 1 \
		&& (input[0] >= '0' && input[0] <= '7') \
		&& (input[0] - '0') < this->_contactIndex)
	{
		this->_displayContact(input[0] - '0');
	}
	else
		std::cout << "Invalid index" << std::endl;
	return ;
}

void	PhoneBook::_displayContact(int index) const
{
	std::cout << "     index" << "|" << "first name" << "|" << " last name" << "|" << "  nickname" << std::endl;
	
	std::string firstName = this->_contact[index].getFirstName();
	std::string lastName = this->_contact[index].getLastName();
	std::string nickname = this->_contact[index].getNickname();

	firstName = PhoneBook::_fixTextForDisplay(firstName);
	lastName = PhoneBook::_fixTextForDisplay(lastName);
	nickname = PhoneBook::_fixTextForDisplay(nickname);

	std::cout << "         " << index << "|" << firstName << "|" \
	<< lastName << "|" << nickname << std::endl;
}

std::string PhoneBook::_fixTextForDisplay( std::string text ) const
{
	if (text.size() > 10)
	{
		text.resize(10);
		text[9] = '.';
	}
	else
		text.insert(0, (10 - text.size()), ' ');
	return (text);
}

int	PhoneBook::_verifyPhoneNumber( std::string phoneNumber ) const
{
	if (phoneNumber.length() == 0)
		return (0);
	for (size_t i = 0; i < phoneNumber.length(); i++)
	{
		if (!isdigit(phoneNumber[i]))
			return (0);
	}
	return (1);
}

int	PhoneBook::_maxContactsReached( void ) const
{
	std::cout << "Maximum amount of contacts reached, your oldest contact will be overwritten." << std::endl;
	std::string userInput;
	while (userInput != "Y" && userInput != "y" && userInput != "n" && userInput != "N")
		userInput = PhoneBook::_getUserInput("Do you want to proceed? (Y/n) ");
	if (userInput == "Y" || userInput == "y")
		return (0);
	return (1);
}
