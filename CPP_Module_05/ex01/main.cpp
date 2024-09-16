#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	std::cout << "Creating forms with invalid grades:" << std::endl;
	try
	{
		std::cout << "Creating form: (1, 0)" << std::endl;
		Form formGrade1_0("formGrade_1_0", 1, 0);
	}
	catch ( std::exception & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Creating form: (0, 1)" << std::endl;
		Form formGrade0_1("formGrade_0_1", 0, 1);
	}
	catch ( std::exception & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Creating form: (150, 151)" << std::endl;
		Form formGrade150_151("formGrade_150_151", 150, 151);
	}
	catch ( std::exception & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Creating form: (151, 150)" << std::endl;
		Form formGrade151_150("formGrade_151_150", 151, 150);
	}
	catch ( std::exception & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Creating forms:" << std::endl;
	Form formGrade150("formGrade150", 150, 150);
	Form formGrade100("formGrade100", 100, 100);
	Form formGrade50("formGrade50", 50, 50);
	Form formGrade10("formGrade10", 10, 10);
	Form formGrade1("formGrade1", 1, 1);
	std::cout << std::endl;

	std::cout << "Creating a bureaucrat (feel free to change its grade to see how it behaves):" << std::endl;
	Bureaucrat *bureaucrat;
	try
	{
		bureaucrat = new Bureaucrat("bureaucrat", 83);
	}
	catch ( std::exception & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Signing forms:" << std::endl;
	bureaucrat->signForm(formGrade150);
	bureaucrat->signForm(formGrade100);
	bureaucrat->signForm(formGrade50);
	bureaucrat->signForm(formGrade10);
	bureaucrat->signForm(formGrade1);
	std::cout << std::endl;

	std::cout << "Notice that a form that was already signed can't be signed again:" << std::endl;
	bureaucrat->signForm(formGrade150);
	std::cout << std::endl;

	std::cout << "Deleting bureaucrat:" << std::endl;
	delete bureaucrat;
	std::cout << std::endl;

	return 0;
}