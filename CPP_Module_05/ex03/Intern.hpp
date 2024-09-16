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
			virtual const char* what() const throw();
	};

private:
	AForm* (*formCreators[3])( std::string target );
	std::string	formNames[3];

	static AForm* createPresidentialPardonForm( std::string target );
	static AForm* createRobotomyRequestForm( std::string target );
	static AForm* createShrubberyCreationForm( std::string target );

};

#endif // INTERN_HPP
