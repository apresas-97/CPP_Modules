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

	std::cout << "The intern is asked to create a form with an unknown name:\n" << std::endl;
	AForm* formPtr4;
	try
	{
		formPtr4 = intern.makeForm("DeliverCoffeeForm", "target");
	}
	catch ( std::exception & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "We create a bureaucrat:\n" << std::endl;
	Bureaucrat buro("Buro", 1);
	std::cout << std::endl;

	std::cout << "The bureaucrat signs the forms, if able to:\n" << std::endl;
	try
	{
		buro.signForm(*formPtr1);
		buro.signForm(*formPtr2);
		buro.signForm(*formPtr3);
	}
	catch ( std::exception & e )
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "The bureaucrat executes the forms, if able to:\n" << std::endl;
	try
	{
		buro.executeForm(*formPtr1);
		buro.executeForm(*formPtr2);
		buro.executeForm(*formPtr3);
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
