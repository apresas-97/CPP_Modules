#include "Array.hpp"

int	main( void )
{
	Array<int> intArray(4);
	Array<bool> boolArray(4);
	Array<char> charArray(4);
	Array<std::string> stringArray(4);

	std::cout << "Creating Arrays:" << std::endl;
	intArray[0] = 21;
	intArray[1] = 42;
	intArray[2] = 84;
	intArray[3] = 168;
	std::cout << "int Array: " << intArray << std::endl;

	boolArray[0] = true;
	boolArray[1] = false;
	boolArray[2] = true;
	boolArray[3] = false;
	std::cout << "bool Array: " << boolArray << std::endl;

	charArray[0] = 'H';
	charArray[1] = 'o';
	charArray[2] = 'l';
	charArray[3] = 'a';
	std::cout << "char Array: " << charArray << std::endl;

	stringArray[0] = "Hola";
	stringArray[1] = "que";
	stringArray[2] = "tal";
	stringArray[3] = "?";
	std::cout << "std::string Array: " << stringArray << std::endl;
	std::cout << std::endl;

	std::cout << "Testing the size function:" << std::endl;
	std::cout << "intArray size: " << intArray.size() << std::endl;
	std::cout << "boolArray size: " << boolArray.size() << std::endl;
	std::cout << "charArray size: " << charArray.size() << std::endl;
	std::cout << "stringArray size: " << stringArray.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Testing the copy constructor:" << std::endl;
	Array<int> intArrayCopy(intArray);
	std::cout << "intArray: " << intArray << std::endl;
	std::cout << "intArrayCopy: " << intArrayCopy << std::endl;
	intArrayCopy[0] = 1;
	intArrayCopy[1] = 2;
	intArrayCopy[2] = 3;
	intArrayCopy[3] = 4;
	std::cout << "We change the copy's values, and check both again:" << std::endl;
	std::cout << "intArray: " << intArray << std::endl;
	std::cout << "intArrayCopy: " << intArrayCopy << std::endl;
	std::cout << std::endl;

	std::cout << "Testing the assignment operator:" << std::endl;
	Array<char> auxArray;
	std::cout << "auxArray: \"" << auxArray << "\"" << std::endl;
	auxArray = charArray;
	std::cout << "After assignment:" << std::endl;
	std::cout << "charArray: " << charArray << std::endl;
	std::cout << "auxArray: " << auxArray << std::endl;
	auxArray[0] = 'C';
	auxArray[1] = 'h';
	auxArray[2] = 'a';
	auxArray[3] = 'o';
	std::cout << "We change the copy's values, and check both again:" << std::endl;
	std::cout << "charArray: " << charArray << std::endl;
	std::cout << "auxArray: " << auxArray << std::endl;
	std::cout << std::endl;

	std::cout << "Trying to access an out of bounds index:" << std::endl;
	try
	{
		std::cout << intArray[4] << std::endl;
	}
	catch( const Array<int>::IndexOutOfRangeException & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Testing default Array:" << std::endl;
	Array<> defaultArray;
	std::cout << defaultArray << std::endl;
	std::cout << std::endl;
	std::cout << "Testing Array with 0 size:" << std::endl;
	Array<int> zeroArray(0);
	std::cout << zeroArray << std::endl;
	std::cout << std::endl;
	std::cout << "Testing Array with \"uninitialised\" contents:" << std::endl;
	Array<int> uninitialisedArray(10);
	std::cout << uninitialisedArray << std::endl;

	return 0;
}
