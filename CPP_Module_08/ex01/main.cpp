#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

void	test_constructors( void );
void	test_span( int size );
void	test_subject( void );
void	test_exceptions( void );

std::vector<int>	create_vector_with_random_values( int size );

int	main( void )
{
	test_constructors();
	std::cout << std::endl;
	test_span(100);
	std::cout << std::endl;
	test_span(10000);
	std::cout << std::endl;
	test_span(1000000);
	std::cout << std::endl;
	test_subject();
	std::cout << std::endl;
	test_exceptions();

	std::cout << ">> Manual test: <<" << std::endl;
	Span sp = Span(10);
	sp.addNumber(28);
	sp.addNumber(-19);
	sp.addNumber(-5);
	sp.addNumber(4);
	sp.addNumber(42);
	sp.addNumber(-42);
	sp.addNumber(-37);
	sp.addNumber(12);
	sp.addNumber(31);
	sp.addNumber(0);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	return 0;
}

std::vector<int>	create_vector_with_random_values( int size )
{
	std::cout << "Creating a vector" << std::endl;
	std::vector<int> vec(size);

	std::cout << "Filling vector with " << size << " random values" << std::endl;
	int i = 0;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (i % 2)
			*it = std::rand();
		else
			*it = -std::rand();
		i++;
	}
	return vec;
}

void	test_constructors( void )
{
	std::cout << ">> Testing constructors: <<\n" << std::endl;
	std::vector<int> vec;
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(17);
	vec.push_back(9);
	vec.push_back(11);

	Span sp1 = Span();
	std::cout << std::endl;

	Span sp2 = Span(5);
	sp2.addRange(vec.begin(), vec.end());
	sp2.print();
	
	Span sp3 = Span(sp2);
	sp3.print();
}

void	test_span( int size )
{
	std::cout << ">> Testing shortestSpan and longestSpan: <<\n" << std::endl;
	std::cout << "Creating a Span of " << size << " elements:" << std::endl;
	Span sp = Span(size);

	std::vector<int> vec = create_vector_with_random_values(size);

	std::cout << "Vector size = " << vec.size() << std::endl;

	std::cout << "Calling addRange" << std::endl;
	sp.addRange(vec.begin(), vec.end());

	// Uncomment if you want to see all the values in the Span
	// 	sp.print();

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void	test_subject( void )
{
	std::cout << ">> Testing the example from the subject: <<\n" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.print();

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void	test_exceptions( void )
{
	std::cout << ">> Testing exceptions: <<\n" << std::endl;
	std::cout << "> Trying to add more numbers than the Span size:" << std::endl;
	try
	{
		Span sp = Span(10);
		for (int i = 0; i <= 10; i++)
			sp.addNumber(i);
	}
	catch ( const std::exception & e )
	{
		std::cout << "Caught exception: " << e.what() << "\n" << std::endl;
	}
	std::cout << "> Trying to calculate a the span in a Span with only one member:" << std::endl;
	try
	{
		Span sp3 = Span(5);
		sp3.addNumber(1);
		sp3.shortestSpan();
	}
	catch ( const std::exception & e )
	{
		std::cout << "Caught exception: " << e.what() << "\n" << std::endl;
	}
	std::cout << "> Trying to calculate a the span in an empty Span:" << std::endl;
	try
	{
		Span sp3 = Span(5);
		sp3.longestSpan();
	}
	catch ( const std::exception & e )
	{
		std::cout << "Caught exception: " << e.what() << "\n" << std::endl;
	}
}
