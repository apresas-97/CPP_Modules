#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	std::cout << "Creating forms:" << std::endl;
	// Creating a ShrubbberyCreationForm
	ShrubberyCreationForm shrubberyCreationForm("home");

	// Creating a RobotomyRequestForm
	RobotomyRequestForm robotomyRequestForm("Cyborg");

	// Creating a PresidentialPardonForm
	PresidentialPardonForm presidentialPardonForm("Misco Jones");
	std::cout << std::endl;

	std::cout << "Creating bureaucrats:" << std::endl;
	// Creating some Bureaucreats
	Bureaucrat Executive("John", 1); // Grade 1 bureaucrat
	Bureaucrat Manager("Jane", 50); // Grade 50 bureaucrat
	Bureaucrat Officer("Jack", 100); // Grade 100 bureaucrat
	Bureaucrat ErrandBoy("Jimmy", 150); // Grade 150 bureaucrat
	std::cout << std::endl;

	std::cout << "Attempting to execute an unsigned form:" << std::endl;
	Executive.executeForm(shrubberyCreationForm);
	Executive.executeForm(robotomyRequestForm);
	Executive.executeForm(presidentialPardonForm);
	std::cout << std::endl;

	std::cout << "Attempting to sign the forms with bureaucrats:" << std::endl;
	std::cout << "Failed attempts:" << std::endl;
	ErrandBoy.signForm(shrubberyCreationForm);
	Officer.signForm(robotomyRequestForm);
	Manager.signForm(presidentialPardonForm);
	std::cout << std::endl;
	std::cout << "Succesful attempts:" << std::endl;
	Officer.signForm(shrubberyCreationForm);
	Manager.signForm(robotomyRequestForm);
	Executive.signForm(presidentialPardonForm);
	std::cout << std::endl;

	std::cout << "Attempting to execute the forms with bureaucrats:" << std::endl;
	std::cout << "Failed attempts:" << std::endl;
	ErrandBoy.executeForm(shrubberyCreationForm);
	Officer.executeForm(robotomyRequestForm);
	Manager.executeForm(presidentialPardonForm);
	std::cout << std::endl;
	std::cout << "Succesful attempts:" << std::endl;
	Officer.executeForm(shrubberyCreationForm);
	std::cout << std::endl;
	Executive.executeForm(robotomyRequestForm);
	std::cout << std::endl;
	Executive.executeForm(presidentialPardonForm);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Attempting to sign an already signed form:" << std::endl;
	Executive.signForm(shrubberyCreationForm);

	std::cout << std::endl;

	std::cout << "Destroying objects and exiting program..." << std::endl;
	return 0;
}