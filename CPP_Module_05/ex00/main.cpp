#include "Bureaucrat.hpp"

int	main( void )
{
	// Try creating a bureaucrat with different grades to see what happens
	try
	{
		Bureaucrat burocrataA("BuroA", 10);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Try incrementing a bureaucrat's grade to see what happens
	Bureaucrat burocrataB("BuroB", 1);
	std::cout << burocrataB << std::endl;

	// If the grade is already 1, incrementing it will throw an exception
	try
	{
		burocrataB.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << burocrataB << std::endl;

	std::cout << std::endl;

	// Try decrementing a bureaucrat's grade to see what happens
	Bureaucrat burocrataC("BuroC", 150);
	std::cout << burocrataC << std::endl;

	// If the grade is already 150, decrementing it will throw an exception
	try
	{
		burocrataC.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << burocrataC << std::endl;
	std::cout << std::endl;

	return 0;
}
