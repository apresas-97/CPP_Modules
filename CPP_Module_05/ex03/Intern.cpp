#include "Intern.hpp"

Intern::Intern( void )
{
	this->formNames[0] = "PresidentialPardonForm";
	this->formNames[1] = "RobotomyRequestForm";
	this->formNames[2] = "ShrubberyCreationForm";
	this->formCreators[0] = &createPresidentialPardonForm;
	this->formCreators[1] = &createRobotomyRequestForm;
	this->formCreators[2] = &createShrubberyCreationForm;
	std::cout << "Intern constructed" << std::endl;
}

Intern::Intern( Intern const &other )
{
	this->formNames[0] = "PresidentialPardonForm";
	this->formNames[1] = "RobotomyRequestForm";
	this->formNames[2] = "ShrubberyCreationForm";
	this->formCreators[0] = &createPresidentialPardonForm;
	this->formCreators[1] = &createRobotomyRequestForm;
	this->formCreators[2] = &createShrubberyCreationForm;
	*this = other;
	std::cout << "Intern copy constructed" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructed" << std::endl;
}

Intern &Intern::operator=( Intern const &other )
{
	if ( this != &other )
	{
		// This has no effect on the Intern object
	}
	return *this;
}

AForm*	Intern::createPresidentialPardonForm( std::string target )
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::createRobotomyRequestForm( std::string target )
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm( std::string target )
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makeForm( std::string formName, std::string targetName )
{	
	for (int i = 0; i < 3; i++)
	{
		if (this->formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](targetName);
		}
	}
	throw Intern::InvalidFormNameException();
}

// Exceptions
const char* Intern::InvalidFormNameException::what() const throw()
{
	return ("Invalid Form name");
}
