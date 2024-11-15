#include "whatever.hpp"
#include <iostream>

int	main( void )
{
	int intA = 21;
	int intB = 42;

	std::cout <<"Comparing ints " << intA << " and " << intB << std::endl;
	std::cout << "Max: " << ::max<int>(intA, intB) << std::endl;
	std::cout << "Min: " << ::min<int>(intA, intB) << std::endl;
	std::cout << "Performing swap" << std::endl;
	std::cout << "Old values: " << intA << ", " << intB << std::endl;
	::swap<int>(intA, intB);
	std::cout << "New values: " << intA << ", " << intB << std::endl;
	std::cout << std::endl;

	float	floatA = 3.1415f;
	float	floatB = 2.7182f;

	std::cout <<"Comparing floats " << floatA << " and " << floatB << std::endl;
	std::cout << "Max: " << ::max<float>(floatA, floatB) << std::endl;
	std::cout << "Min: " << ::min<float>(floatA, floatB) << std::endl;
	std::cout << "Performing swap" << std::endl;
	std::cout << "Old values: " << floatA << ", " << floatB << std::endl;
	::swap<float>(floatA, floatB);
	std::cout << "New values: " << floatA << ", " << floatB << std::endl;
	std::cout << std::endl;

	long	longA = 4444L;
	long	longB = 2222L;

	std::cout <<"Comparing longs " << longA << " and " << longB << std::endl;
	std::cout << "Max: " << ::max<long>(longA, longB) << std::endl;
	std::cout << "Min: " << ::min<long>(longA, longB) << std::endl;
	std::cout << "Performing swap" << std::endl;
	std::cout << "Old values: " << longA << ", " << longB << std::endl;
	::swap<long>(longA, longB);
	std::cout << "New values: " << longA << ", " << longB << std::endl;
	std::cout << std::endl;

	double	doubleA = 3.1415926535;
	double	doubleB = 2.7182818284;

	std::cout <<"Comparing doubles " << doubleA << " and " << doubleB << std::endl;
	std::cout << "Max: " << ::max<double>(doubleA, doubleB) << std::endl;
	std::cout << "Min: " << ::min<double>(doubleA, doubleB) << std::endl;
	std::cout << "Performing swap" << std::endl;
	std::cout << "Old values: " << doubleA << ", " << doubleB << std::endl;
	::swap<double>(doubleA, doubleB);
	std::cout << "New values: " << doubleA << ", " << doubleB << std::endl;
	std::cout << std::endl;

	char	charA = 'A';
	char	charB = 'B';

	std::cout <<"Comparing chars '" << charA << "' and '" << charB << "'" << std::endl;
	std::cout << "Max: '" << ::max<char>(charA, charB) << "'" << std::endl;
	std::cout << "Min: '" << ::min<char>(charA, charB) << "'" << std::endl;
	std::cout << "Performing swap" << std::endl;
	std::cout << "Old values: '" << charA << "', '" << charB << "'" << std::endl;
	::swap<char>(charA, charB);
	std::cout << "New values: '" << charA << "', '" << charB << "'" << std::endl;
	std::cout << std::endl;

	std::string stringA = "chaine1";
	std::string stringB = "chaine2";

	std::cout <<"Comparing std::strings \"" << stringA << "\" and \"" << stringB << "\"" << std::endl;
	std::cout << "Max: \"" << ::max<std::string>(stringA, stringB) << "\"" << std::endl;
	std::cout << "Min: \"" << ::min(stringA, stringB) << "\"" << std::endl;
	std::cout << "Performing swap" << std::endl;
	std::cout << "Old values: \"" << stringA << "\", \"" << stringB << "\"" << std::endl;
	::swap(stringA, stringB);
	std::cout << "New values: \"" << stringA << "\", \"" << stringB << "\"" << std::endl;

	std::cout << std::endl;

	std::cout << "Checking that min and max, when equal, return the second variable:" << std::endl;
	int	first = 0;
	int	second = 0;
	std::cout << "first = " << first << std::endl;
	std::cout << "second = " << second << std::endl;
	const int & returned_max = ::max(first, second);
	const int & returned_min = ::min(first, second);
	std::cout << "returned_min = " << returned_min << std::endl;
	std::cout << "returned_max = " << returned_max << std::endl;
	first = 1;
	second = 2;
	std::cout << "first = " << first << std::endl;
	std::cout << "second = " << second << std::endl;
	std::cout << "returned_min = " << returned_min << std::endl;
	std::cout << "returned_max = " << returned_max << std::endl;

	return 0;
}
