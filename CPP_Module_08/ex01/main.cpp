#include "Span.hpp"
#include <iostream>
#include <unistd.h>
#include <vector>

int	main( void )
{
	// std::cout << "Testing constructors:" << std::endl;
	// {
	// 	int* array = new int[5];
	// 	array[0] = 1;
	// 	array[1] = 2;
	// 	array[2] = 3;
	// 	array[3] = 4;
	// 	array[4] = 5;
	
	// 	Span sp1 = Span();
	// 	Span sp2 = Span(5);
	// 	Span sp3 = Span(array, 5);
	// 	Span sp4 = Span(sp3);
		
	// 	delete [] array;
	// }
	Span sp = Span(5);
	sp.addMember(6);
	sp.addMember(3);
	sp.addMember(17);
	sp.addMember(9);
	sp.addMember(11);

	// sp.randomFill();

	// create a vector
	// std::vector<int> vec;
	// vec.push_back(42);
	// vec.push_back(21);
	// vec.push_back(84);


	sp.print();

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;


	return 0;
}
