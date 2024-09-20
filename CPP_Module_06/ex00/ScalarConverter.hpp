#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <exception>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>

class ScalarConverter
{

private:

	ScalarConverter( void );
	ScalarConverter( ScalarConverter const &other );
	~ScalarConverter();
	ScalarConverter &operator=( ScalarConverter const &other );

public:

	static void convert( const std::string & input );
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

private:
	
	static bool	input_is_int( const std::string & input );
	static bool	input_is_float( const std::string & input );
	static bool	input_is_double( const std::string & input );
	static int	get_meaningful_decimals( const std::string & input );
	static void	display_char( const char c , const long l );
	static void	display_int( const int i, const long l );
	static void	display_float( const float f, const int decimals );
	static void	display_double( const double d, const int decimals );

};

#endif // SCALARCONVERTER_HPP
