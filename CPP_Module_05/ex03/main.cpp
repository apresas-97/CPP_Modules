#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main( void )
{
	std::cout << "Creating the Intern" << std::endl;

	Intern intern;

	std::cout << std::endl;

	std::cout << "The intern creates each type of form:\n" << std::endl;

	AForm *formPtr1;
	AForm *formPtr2;
	AForm *formPtr3;
	
	formPtr1 = intern.makeForm("ShrubberyCreationForm", "home");
	std::cout << std::endl;

	formPtr2 = intern.makeForm("RobotomyRequestForm", "Cyborg");
	std::cout << std::endl;

	formPtr3 = intern.makeForm("PresidentialPardonForm", "Misco Jones");
	std::cout << std::endl;

	std::cout << "We create a bureaucrat:\n" << std::endl;
	Bureaucrat executive("Executive", 1);
	std::cout << std::endl;

	std::cout << "The bureaucrat signs the forms, if able to:\n" << std::endl;
	try
	{
		executive.signForm(*formPtr1);
		executive.signForm(*formPtr2);
		executive.signForm(*formPtr3);
	}
	catch ( std::exception & e )
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "The bureaucrat executes the forms, if able to:\n" << std::endl;
	try
	{
		executive.executeForm(*formPtr1);
		executive.executeForm(*formPtr2);
		executive.executeForm(*formPtr3);
	}
	catch  (std::exception & e )
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Deleting the forms:" << std::endl;
	delete formPtr1;
	delete formPtr2;
	delete formPtr3;
	std::cout << std::endl;

	return 0;
}