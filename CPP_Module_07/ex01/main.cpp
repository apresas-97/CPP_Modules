#include <cstddef>
#include <iostream>
#include "iter.hpp"
#include "functions.hpp"

int	main( void )
{
	std::cout << "Iter with int:" << std::endl;
	int intArray[] = { 21, 42, 84, 168, 336 };
	size_t intArrayLen = sizeof(intArray) / sizeof(intArray[0]);

	::iter<int>(intArray, intArrayLen, print<int>);
	std::cout << std::endl;

	std::cout << "Iter with bool:" << std::endl;
	bool	boolArray[] = { true, false, true, false, true };
	size_t	boolArrayLen = sizeof(boolArray) / sizeof(boolArray[0]);

	::iter<bool>(boolArray, boolArrayLen, print<bool>);
	std::cout << std::endl;

	std::cout << "Iter with float:" << std::endl;
	float floatArray[] = { 21.42f, 42.84f, 84.168f, 168.336f, 336.672f };
	size_t floatArrayLen = sizeof(floatArray) / sizeof(floatArray[0]);

	::iter<float>(floatArray, floatArrayLen, print);
	std::cout << std::endl;

	std::cout << "Iter with long:" << std::endl;
	long longArray[] = { 21L, 42L, 84L, 168L, 336L };
	size_t longArrayLen = sizeof(longArray) / sizeof(longArray[0]);

	::iter<long>(longArray, longArrayLen, print);
	std::cout << std::endl;

	std::cout << "Iter with char:" << std::endl;
	char	charArray[] = { 'a', 'b', 'c', 'd', 'e', static_cast<char>(128) };
	size_t charArrayLen = sizeof(charArray) / sizeof(charArray[0]);

	::iter<char>(charArray, charArrayLen, print);
	std::cout << std::endl;

	std::cout << "Iter with std::string:" << std::endl;
	std::string stringArray[] = { "Hello,", "World!", "Hola", "que", "tal", "?" };
	size_t	stringArrayLen = sizeof(stringArray) / sizeof(stringArray[0]);

	::iter<std::string>(stringArray, stringArrayLen, print);

	return 0;
}
