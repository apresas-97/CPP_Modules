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

bool	istype_iter(std::string str, size_t st, int (*f)(int));

bool	string_is_char( std::string str )
{
	if (str.size() == 1 && std::isdigit(str[0]) == false)
		return true;
	return false;
}

bool	string_is_int( std::string str )
{
	size_t	i = 0;
	if ( str[i] == '+' || str[i] == '-' )
		i++;
	// Need to bypass leading zeros too
	for (;i < str.size(); i++)
	{
		if (str[i] != '0')
			break;
	}
	if (i == str.size())
		return true; // If the string is only zeros, it's an int, 0
	for (;i < str.size(); i++)
	{
		if (std::isdigit(str[i]) == false)
			return false;
	}
	if ((str[0] == '-' || str[0] == '+') && str.size() == 1)
		return false;
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

// Cases to fix
// 0.f
// .3f
bool	string_is_float(std::string str )
{
	size_t	i = 0;

	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	if ( str[i] == '+' || str[i] == '-' )
		i++;
	for (;i < str.size(); i++)
	{
		if (std::isdigit(str[i]) == false)
			break;
	}
	if (str[i] == '.')
		i++;
	if (i == str.size())
		return false;
	for (;i < str.size(); i++)
	{
		if (std::isdigit(str[i]) == false)
			break;
	}
	if (str[i] != 'f')
		return false;
	if (str[i] == 'f')
		i++;
	if (i == str.size())
		return true;
	return false;
}

// Cases to fix
// .3
bool	string_is_double( std::string str )
{
	size_t	i = 0;

	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	if ( str[i] == '+' || str[i] == '-' )
		i++;
	for (;i < str.size(); i++)
	{
		if (std::isdigit(str[i]) == false)
			break;
	}
	if (str[i] == '.')
		i++;
	if (i == str.size())
		return false;
	for (;i < str.size(); i++)
	{
		if (std::isdigit(str[i]) == false)
			break;
	}
	if (i == str.size())
		return true;
	return false;
}

void	display_char( char c, std::string input )
{
	if (std::isprint(c) == false)
		std::cout << "char: Non displayable" << std::endl;
	else if (input == "nan" || input == "-inf" || input == "+inf" || input == "nanf" || input == "-inff" || input == "+inff")
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;
}

void	display_int( int i, std::string input )
{
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "nanf" || input == "-inff" || input == "+inff")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	display_float( float f, std::string input )
{
	(void)input;
	// if (f - static_cast<int>(f) == 0)
		// std::cout << "float: " << std::fixed << f << ".0f" << std::endl;
	// else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void	display_double( double d, std::string input )
{
	(void)input;
	// if (d - static_cast<int>(d) == 0)
		// std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	// else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert( std::string input )
{
	char	charResult = 0;
	int		intResult = 0;
	float	floatResult = 0;
	double	doubleResult = 0;

	if (input.empty() == true)
		throw ScalarConverter::EmptyInput(); //? Maybe just display "Empty input" and return
	if (string_is_char(input) == true)
	{
		std::cout << "Input is char" << std::endl;
		charResult = input[0];
		intResult = static_cast<int>(charResult);
		floatResult = static_cast<float>(charResult);
		doubleResult = static_cast<double>(charResult);
	}
	else if (string_is_int(input) == true)
	{
		std::cout << "Input is int" << std::endl;
		intResult = std::atoi(input.c_str());
		charResult = static_cast<char>(intResult); // If intResult is out of char bounds, it should say Impossible for chars
		floatResult = static_cast<float>(intResult);
		doubleResult = static_cast<double>(intResult);
	}
	else if (string_is_float(input) == true)
	{
		std::cout << "Input is float" << std::endl;
		floatResult = std::strtof(input.c_str(), NULL);
		charResult = static_cast<char>(floatResult);
		intResult = static_cast<int>(floatResult);
		doubleResult = static_cast<double>(floatResult);
	}
	else if (string_is_double(input) == true)
	{
		std::cout << "Input is double" << std::endl;
		doubleResult = std::strtod(input.c_str(), NULL);
		charResult = static_cast<char>(doubleResult);
		intResult = static_cast<int>(doubleResult);
		floatResult = static_cast<float>(doubleResult);
	}
	else
	{
		// throw ScalarConverter::WrongInput();
		std::cout << "???" << std::endl;
		return ;
	}
	display_char(charResult, input);
	display_int(intResult, input);
	display_float(floatResult, input);
	display_double(doubleResult, input);
	return ;
}

bool	istype_iter(std::string str, size_t st, int (*f)(int))
{
	for (size_t i = st; i < str.size(); i++)
	{
		if (f(str[i]) == 0)
			return false;
	}
	return true;
}

const char*	ScalarConverter::WrongInput::what() const throw()
{
	return ("Wrong input");
}

const char*	ScalarConverter::EmptyInput::what() const throw()
{
	return ("Empty input");
}
