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

// Char
bool	string_is_char( std::string str )
{
	// if (str.size() == 1 && std::isdigit(str[0]) == false)
	// 	return true;
	if (str.size() == 1)
		return true;
	return false;
}

char	string_to_char( const std::string & str )
{
	return str[0];
}

void	display_char( char c, int i, std::string input )
{
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "nanf" || input == "-inff" || input == "+inff")
		std::cout << "char: impossible" << std::endl;
	else if (i > 255)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;
}
//

// Int
bool	string_is_int( const std::string & str )
{
	size_t	i = 0;
	if (str.empty() == true)
		return false;
	if ( str[i] == '+' || str[i] == '-' )
		i++;
	if (i == str.size())
		return false;
	while (i < str.size() && str[i] == '0')
		i++;
	if (i == str.size())
		return true;
	for (;i < str.size(); i++)
	{
		if (std::isdigit(str[i]) == false)
			return false;
	}
	if (str[0] == '-' && str.size() == 11 && str.compare("-2147483648") > 0)
		return false;
	else if (str[0] == '+' && str.size() == 11 && str.compare("+2147483647") > 0)
		return false;
	else if (str.size() == 10 && str.compare("2147483647") > 0)
		return false;
	else if (str.size() > 11)
		return false;
	return true;
}

int	string_to_int( const std::string & str )
{
	return std::atoi(str.c_str());
}

void	display_int( int i, std::string input )
{
	// Falta que imprima "impossible" si el valor es mayor a INT_MAX o menor a INT_MIN
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "nanf" || input == "-inff" || input == "+inff")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}
//

// Float
bool	string_is_float(std::string str )
{
	// Maybe?
	if (str.empty() == true)
		return false;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	char	*endptr = NULL;
	std::strtof(str.c_str(), &endptr);
	if (*endptr != 'f' || &str[str.size() - 1] != endptr)
		return false;
	return true;
}

float	string_to_float( const std::string & str )
{
	return std::strtof(str.c_str(), NULL);
}

void	display_float( float f, std::string input )
{
	(void)input;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}
//

// Double
bool	string_is_double( std::string str )
{
	if (str.empty() == true)
		return false;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	char	*endptr = NULL;
	std::strtod(str.c_str(), &endptr);
	if (*endptr != '\0')
		return false;
	return true;
}

double	string_to_double( const std::string & str )
{
	return std::strtod(str.c_str(), NULL);
}

void	display_double( double d, std::string input )
{
	(void)input;
	std::cout << "double: " << std::fixed << d << std::endl;
}
//

template <typename T>
void	cast_and_print(T value, const std::string & input)
{
	char	charResult = static_cast<char>(value);
	int		intResult = static_cast<int>(value);
	float	floatResult = static_cast<float>(value);
	double	doubleResult = static_cast<double>(value);

	display_char(charResult, intResult, input);
	std::cout << "int: " << intResult << std::endl;
	std::cout << "float: " << std::fixed << floatResult << "f" << std::endl;
	std::cout << "double: " << std::fixed << doubleResult << std::endl;
}

void	ScalarConverter::convert( const std::string & input )
{
	if (input.empty() == true)
		throw ScalarConverter::EmptyInput(); //? Maybe just display "Empty input" and return

	if (string_is_char(input) == true)
	{
		std::cout << "char" << std::endl;
		cast_and_print(string_to_char(input), input);
		return ;
	}

	// if (input.size() == 1 && std::isdigit(input[0]) == false)
	// {
	// 	std::cout << "char" << std::endl;
	// 	cast_and_print(input[0]);
	// }

	if (string_is_int(input) == true)
	{
		std::cout << "int" << std::endl;
		cast_and_print(string_to_int(input), input);
		return ;
	}
	// char *endptr = NULL;
	// long intPlaceholder = std::strtol(input.c_str(), &endptr, 10);
	// if (endptr != input.c_str() && *endptr == '\0' && intPlaceholder >= INT_MIN && intPlaceholder <= INT_MAX)
	// {
	// 	std::cout << "int" << std::endl;
	// 	int intValue = static_cast<int>(intPlaceholder);
	// 	cast_and_print(intValue);
	// }

	char *endptr = NULL;
	float floatPlaceholder = std::strtof(input.c_str(), &endptr);
	if (*endptr == 'f' && &input[input.size() - 1] == endptr)
	{
		std::cout << "float" << std::endl;
		std::cout << "value: " << std::fixed << floatPlaceholder << "f" << std::endl;
		cast_and_print(floatPlaceholder, input);
		return ;
	}

	endptr = NULL;
	double doublePlaceholder = std::strtod(input.c_str(), &endptr);
	if (*endptr == '\0')
	{
		std::cout << "double" << std::endl;
		std::cout << "value: " << std::fixed << doublePlaceholder << std::endl;
		cast_and_print(doublePlaceholder, input);
		return ;
	}


	return ;
}

// Execptions
const char* ScalarConverter::WrongInput::what() const throw()
{
	return "Wrong input";
}

const char* ScalarConverter::EmptyInput::what() const throw()
{
	return "Empty input";
}
