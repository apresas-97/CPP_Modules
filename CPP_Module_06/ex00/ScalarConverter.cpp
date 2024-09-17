#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
	// Irrelevant, this class is not instantiable
}

ScalarConverter::ScalarConverter( ScalarConverter const &other )
{
	// Irrelevant, this class is not instantiable
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
	// Irrelevant, this class is not instantiable
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &other )
{
	// Irrelevant, this class is not instantiable
	if ( this != &other )
	{

	}
	return *this;
}

void ScalarConverter::convert( std::string input )
{
	// First, recognize the type of the input
	
	// If input == "nan", "inf" or "-inf", it's a double
	// Or if input contains a dot, and doesn't end in 'f', it's a double
	
	// If input == "nanf", "inff" or "-inff", it's a float
	// Or if input ends in 'f', it's a float

	// If input == any displayable character, it's a char

	// If input == any number, it's an int? At least if it's within range

	int type = 0;
	if ( input == "nan" || input == "inf" || input == "-inf" )
		type = 4;
	else if ( input == "nanf" || input == "inff" || input == "-inff" )
		type = 3;

	// For the number to be a float / double, it has to meet these criteria:

	// It contains at least a digit
	// Then it contains a dot
	// Then it contains at least another digit

	// Afterwards, if the following character is an 'f', it's a float
	// But if there is any character after the 'f', it's invalid

	// If all the characters after the '.' are digits, it's a double

	// If the input contains only digits, it should be an int
	// I don't know what to do about the limits of int (or floats and doubles)

	// If the input contains only one character, and it is not a digit, then it's a char
	// Though maybe it would be easier if all inputs with only one character I consider
	// as char

	// If the input contains more than one character, it is either
	// "int", "float" or "double"

	// We seek a '.'
	// If found, 'int' is discarded

	////////////

	// If there is only one character, it is char

	if (input.length() == 1)
		// it is char
	

	// Else
	// Verify this structure:
	// <any amount of digits><dot><any amount of digits><optionally an 'f'>

}
