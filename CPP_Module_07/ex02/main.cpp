#include "Array.hpp"

int	main( void )
{
	Array<int> intArray(4);
	Array<bool> boolArray(4);
	Array<char> charArray(4);

	intArray[0] = 21;
	intArray[1] = 42;
	intArray[2] = 84;
	intArray[3] = 168;
	std::cout << intArray << std::endl;

	boolArray[0] = true;
	boolArray[1] = false;
	boolArray[2] = true;
	boolArray[3] = false;
	std::cout << boolArray << std::endl;

	charArray[0] = 'H';
	charArray[1] = 'o';
	charArray[2] = 'l';
	charArray[3] = 'a';
	std::cout << charArray << std::endl;

	Array<char> string("Hello, World!");
	std::cout << string << std::endl;

	std::cout << "Testing the size function:" << std::endl;
	std::cout << "intArray size: " << intArray.size() << std::endl;
	std::cout << "boolArray size: " << boolArray.size() << std::endl;
	std::cout << "charArray size: " << charArray.size() << std::endl;
	std::cout << "string size: " << string.size() << std::endl;
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
	Array<char> emptyString;
	std::cout << "emptyString: \"" << emptyString << "\"" << std::endl;
	emptyString = string;
	std::cout << "After assignment:" << std::endl;
	std::cout << "string: " << string << std::endl;
	std::cout << "emptyString: " << emptyString << std::endl;
	emptyString[0] = ' ';
	emptyString[1] = 'H';
	emptyString[2] = 'o';
	emptyString[3] = 'l';
	emptyString[4] = 'a';
	std::cout << "We change the copy's values, and check both again:" << std::endl;
	std::cout << "string: " << string << std::endl;
	std::cout << "emptyString: " << emptyString << std::endl;
	std::cout << std::endl;

	std::cout << "\nTrying to access an out of bounds index:" << std::endl;
	try
	{
		std::cout << intArray[4] << std::endl;
	}
	catch( const Array<int>::IndexOutOfRangeException & e )
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Accessing elements of a default Array:" << std::endl;
	Array<> defaultArray;
	std::cout << defaultArray << std::endl;

	return 0;
}
