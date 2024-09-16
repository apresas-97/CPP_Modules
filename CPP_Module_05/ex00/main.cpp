#include "Bureaucrat.hpp"

int	main( void )
{
	std::cout << "Creating a bureaucrat (feel free to change its grade to see what happens)" << std::endl;
	Bureaucrat *bureaucrat;
	try
	{
		bureaucrat = new Bureaucrat("Buro", 42);
	}
	catch ( std::exception & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
	std::cout << std::endl;

	std::cout << "Checking the output of the << operator overload:" << std::endl;
	std::cout << *bureaucrat << std::endl;
	std::cout << std::endl;

	std::cout << "Incrementing the bureaucrat's grade to the maximum level (1):" << std::endl;
	try
	{
		std::cout << "Initial state: " << *bureaucrat << std::endl;
		for (int i = bureaucrat->getGrade(); i > 1; i--)
			bureaucrat->incrementGrade();
		std::cout << "Final state: " << *bureaucrat << std::endl;
		std::cout << "Trying to increment the bureaucrat's grade again:" << std::endl;
		bureaucrat->incrementGrade();
	}
	catch ( std::exception & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Decrementing the bureaucrat's grade to the minimum level (150):" << std::endl;
	try
	{
		std::cout << "Initial state: " << *bureaucrat << std::endl;
		for (int i = bureaucrat->getGrade(); i < 150; i++)
			bureaucrat->decrementGrade();
		std::cout << "Final state: " << *bureaucrat << std::endl;
		std::cout << "Trying to decrement the bureaucrat's grade again:" << std::endl;
		bureaucrat->decrementGrade();
	}
	catch ( std::exception & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Deleting the bureaucrat" << std::endl;
	delete bureaucrat;
	std::cout << std::endl;

	return 0;
}
