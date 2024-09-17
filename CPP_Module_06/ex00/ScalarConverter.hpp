#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{

private:

	ScalarConverter( void );
	ScalarConverter( ScalarConverter const &other );
	~ScalarConverter();
	ScalarConverter &operator=( ScalarConverter const &other );

public:

	static void convert( std::string input );

};

#endif // SCALARCONVERTER_HPP
