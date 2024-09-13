#ifndef INTERN_HPP
#define INTERN_HPP

#include <stdexcept>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{

public:

	Intern( void );
	Intern( Intern const &other );
	~Intern();
	Intern &operator=( Intern const &other );

	AForm* makeForm( std::string formName, std::string targetName );

	class InvalidFormNameException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Invalid Form name");
			}
	};

private:
	std::string	formNames[3];

};

#endif // INTERN_HPP
