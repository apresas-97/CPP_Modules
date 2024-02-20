#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string command;

	while (!std::cin.eof())
	{
		std::cout << "Introduce a command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			PhoneBook.add();
		else if (command == "SEARCH")
			PhoneBook.search();
		else if (command == "EXIT")
			break ;
	}
	if (std::cin.eof())
		std::cout << std::endl;
	return (0);
}
