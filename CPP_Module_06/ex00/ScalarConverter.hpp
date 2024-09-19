#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cmath>

class ScalarConverter
{

private:

	ScalarConverter( void );
	ScalarConverter( ScalarConverter const &other );
	~ScalarConverter();
	ScalarConverter &operator=( ScalarConverter const &other );

public:

	class WrongInput : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class EmptyInput : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	static void convert( const std::string & input );

};

#endif // SCALARCONVERTER_HPP
