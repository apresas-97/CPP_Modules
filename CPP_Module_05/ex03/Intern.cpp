#include "Intern.hpp"

Intern::Intern( void )
{
	this->formNames[0] = "PresidentialPardonForm";
	this->formNames[1] = "RobotomyRequestForm";
	this->formNames[2] = "ShrubberyCreationForm";
}

Intern::Intern( Intern const &other )
{
	*this = other;
}

Intern::~Intern()
{

}

Intern &Intern::operator=( Intern const &other )
{
	if ( this != &other )
	{

	}
	return *this;
}

AForm*	Intern::makeForm( std::string formName, std::string targetName )
{
	AForm*	form = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (formName == this->formNames[i])
		{
			if (formName == this->formNames[0])
				form = new PresidentialPardonForm(targetName);
			else if (formName == this->formNames[1])
				form = new RobotomyRequestForm(targetName);
			else if (formName == this->formNames[2])
				form = new ShrubberyCreationForm(targetName);
			return form;
		}
	}
	throw Intern::InvalidFormNameException();
	return form;
}
