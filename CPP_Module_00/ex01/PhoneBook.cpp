#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contactIndex = 0;
	this->contactCount = 0;
	std::cout << "Welcome to Crappy Awesome Phonebook!" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Crappy Awesome Phonebook is shutting down" << std::endl;
}

std::string	PhoneBook::getUserInput( std::string prompt ) const
{
	std::string	userInput;
	while (userInput.empty() && !std::cin.eof())
	{
		std::cout << prompt;
		std::getline(std::cin, userInput);
	}
	return (userInput);
}

void PhoneBook::add()
{
	std::cout << "Adding a new contact" << std::endl;

	if (PhoneBook::contactCount >= 8 && PhoneBook::maxContactsReached() == 1)
		return ;

	std::string firstNameAux = PhoneBook::getUserInput("First name: ");
	std::string lastNameAux = PhoneBook::getUserInput("Last name: ");
	std::string nicknameAux = PhoneBook::getUserInput("Nickname: ");
	std::string phoneNumberAux;
	while (PhoneBook::verifyPhoneNumber(phoneNumberAux) != 1)
		phoneNumberAux = PhoneBook::getUserInput("Phone number: ");
	std::string darkestSecretAux = PhoneBook::getUserInput("Darkest secret: ");

	if (std::cin.eof())
		return ;

	this->contact[contactIndex % 8].setFirstName(firstNameAux);
	this->contact[contactIndex % 8].setLastName(lastNameAux);
	this->contact[contactIndex % 8].setNickname(nicknameAux);
	this->contact[contactIndex % 8].setPhoneNumber(phoneNumberAux);
	this->contact[contactIndex % 8].setDarkestSecret(darkestSecretAux);

	this->contactIndex++;
	this->contactCount++;

	if (this->contactIndex == 2)
		std::cout << this->contact[0].getLastName() << std::endl;

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
		&& (input[0] - '0') < this->contactIndex)
	{
		this->displayContact(input[0] - '0');
	}
	else
		std::cout << "Invalid index" << std::endl;
	return ;
}

void	PhoneBook::displayContact(int index) const
{
	std::cout << "     index" << "|" << "first name" << "|" << " last name" << "|" << "  nickname" << std::endl;
	
	std::string firstName = this->contact[index].getFirstName();
	std::string lastName = this->contact[index].getLastName();
	std::string nickname = this->contact[index].getNickname();

	firstName = PhoneBook::fixTextForDisplay(firstName);
	lastName = PhoneBook::fixTextForDisplay(lastName);
	nickname = PhoneBook::fixTextForDisplay(nickname);

	std::cout << "         " << index << "|" << firstName << "|" \
	<< lastName << "|" << nickname << std::endl;
}

std::string PhoneBook::fixTextForDisplay( std::string text ) const
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

int	PhoneBook::verifyPhoneNumber( std::string phoneNumber ) const
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

int	PhoneBook::maxContactsReached( void ) const
{
	std::cout << "Maximum amount of contacts reached, your oldest contact will be overwritten." << std::endl;
	std::string userInput;
	while (userInput != "Y" && userInput != "y" && userInput != "n" && userInput != "N")
		userInput = PhoneBook::getUserInput("Do you want to proceed? (Y/n) ");
	if (userInput == "Y" || userInput == "y")
		return (0);
	return (1);
}
