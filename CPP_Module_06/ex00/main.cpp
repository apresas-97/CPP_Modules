#include "ScalarConverter.hpp"

void	test( void );

int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "Usage: ./scalar_converter <input>" << std::endl;
		return 1;
	}
	std::string input = argv[1];
	try
	{
		ScalarConverter::convert(input);
	}
	catch( const std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return 1;
	}
	
	// test();

	return 0;
}

void	char_test( void )
{
	std::cout << "Testing chars: ------------------------------" << std::endl;
	std::cout << "'a':" << std::endl;
	ScalarConverter::convert("a");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "'1':" << std::endl;
	ScalarConverter::convert("1");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "' ':" << std::endl;
	ScalarConverter::convert(" ");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "'!':" << std::endl;
	ScalarConverter::convert("!");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "'0':" << std::endl;
	ScalarConverter::convert("0");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "'9':" << std::endl;
	ScalarConverter::convert("9");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "'z':" << std::endl;
	ScalarConverter::convert("z");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "'A':" << std::endl;
	ScalarConverter::convert("A");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "'Z':" << std::endl;
	ScalarConverter::convert("Z");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "'~':" << std::endl;
	ScalarConverter::convert("~");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "'.':" << std::endl;
	ScalarConverter::convert(".");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "']':" << std::endl;
	ScalarConverter::convert("]");	
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Char tests done" << std::endl;
}

void	int_test( void )
{
	std::cout << "Testing ints: -------------------------------" << std::endl;
	std::cout << "00:" << std::endl;
	ScalarConverter::convert("00");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-00000000000000000000000000000000000000000000000001:" << std::endl;
	ScalarConverter::convert("-00000000000000000000000000000000000000000000000001");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "42:" << std::endl;
	ScalarConverter::convert("42");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "255:" << std::endl;
	ScalarConverter::convert("255");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "256:" << std::endl;
	ScalarConverter::convert("256");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "902486:" << std::endl;
	ScalarConverter::convert("902486");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-531089:" << std::endl;
	ScalarConverter::convert("-531089");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "2147483647:" << std::endl;
	ScalarConverter::convert("2147483647");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-2147483648:" << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << "Invalid ints: -------------------------------" << std::endl;
	std::cout << "2147483648:" << std::endl;
	try
	{
		ScalarConverter::convert("2147483648");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-2147483649:" << std::endl;
	try
	{
		ScalarConverter::convert("-2147483649");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "++1:" << std::endl;
	try
	{
		ScalarConverter::convert("++1");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "--42:" << std::endl;
	try
	{
		ScalarConverter::convert("--42");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\"123 \":" << std::endl;
	try
	{
		ScalarConverter::convert("123 ");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "1234A5678:" << std::endl;
	try
	{
		ScalarConverter::convert("1234A5678");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Int tests done" << std::endl;
}

void	float_test( void )
{
	std::cout << "Testing floats: -----------------------------" << std::endl;
	std::cout << "0.0f:" << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "0.042f:" << std::endl;
	ScalarConverter::convert("0.042f");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "42.42f:" << std::endl;
	ScalarConverter::convert("42.42f");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "518451.093f:" << std::endl;
	ScalarConverter::convert("518451.093f");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-0.0f:" << std::endl;
	ScalarConverter::convert("-0.0f");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-00000000000.123f:" << std::endl;
	ScalarConverter::convert("-00000000000.123f");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "2147483647.0f:" << std::endl;
	ScalarConverter::convert("2147483647.0f");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-2147483648.0f:" << std::endl;
	ScalarConverter::convert("-2147483648.0f");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "99999999999999999.0f:" << std::endl;
	ScalarConverter::convert("99999999999999999.0f");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-777777777777777.0f:" << std::endl;
	ScalarConverter::convert("-777777777777777.0f");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << ".5f:" << std::endl;
	ScalarConverter::convert(".5f");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "10.f:" << std::endl;
	ScalarConverter::convert("10.f");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "nanf:" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-inff:" << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "+inff:" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << "Invalid floats: -----------------------------" << std::endl;
	std::cout << "42f:" << std::endl;
	try
	{
		ScalarConverter::convert("42f");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\".f\":" << std::endl;
	try
	{
		ScalarConverter::convert(".f");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\"+.f\":" << std::endl;
	try
	{
		ScalarConverter::convert("+.f");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\"-.f\":" << std::endl;
	try
	{
		ScalarConverter::convert("-.f");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\"+nanf\":" << std::endl;
	try
	{
		ScalarConverter::convert("+nanf");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\"1.2A34f\":" << std::endl;
	try
	{
		ScalarConverter::convert("1.2A34f");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\"1 .234f\":" << std::endl;
	try
	{
		ScalarConverter::convert("1 .234f");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\"1.234 f\":" << std::endl;
	try
	{
		ScalarConverter::convert("1.234 f");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\"1.234f \":" << std::endl;
	try
	{
		ScalarConverter::convert("1.234f ");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\" 1.234f\":" << std::endl;
	try
	{
		ScalarConverter::convert(" 1.234f");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\".5.5f\":\"" << std::endl;
	try
	{
		ScalarConverter::convert(".5.5f");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Float tests done" << std::endl;
}

void	double_test( void )
{
	std::cout << "Testing doubles: ----------------------------" << std::endl;
	std::cout << "0.0:" << std::endl;
	ScalarConverter::convert("0.0");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "0.042::" << std::endl;
	ScalarConverter::convert("0.042");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "42.42:" << std::endl;
	ScalarConverter::convert("42.42");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "784306.74391:" << std::endl;
	ScalarConverter::convert("784306.74391");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-000.007:" << std::endl;
	ScalarConverter::convert("-000.007");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "+0123.4567:" << std::endl;
	ScalarConverter::convert("+0123.4567");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "+127.0:" << std::endl;
	ScalarConverter::convert("+127.0");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "nan:" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-inf:" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "+inf:" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "2147483647.0:" << std::endl;
	ScalarConverter::convert("2147483647.0");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-2147483648.0:" << std::endl;
	ScalarConverter::convert("-2147483648.0");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "99999999999999999.0:" << std::endl;
	ScalarConverter::convert("99999999999999999.0");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "-777777777777777.0:" << std::endl;
	ScalarConverter::convert("-777777777777777.0");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789.123456789123456789123456789123456789123456789" << std::endl;
	ScalarConverter::convert("123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789.123456789123456789123456789123456789123456789");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "1000[...]000.0 (310 digits):" << std::endl; 
	ScalarConverter::convert("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0");
	std::cout << "Invalid doubles: ----------------------------" << std::endl;
	std::cout << "100000000000000000000:" << std::endl;
	try
	{
		ScalarConverter::convert("100000000000000000000");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "++10.0:" << std::endl;
	try
	{
		ScalarConverter::convert("++10.0");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "--5000.0:" << std::endl;
	try
	{
		ScalarConverter::convert("--50.0");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\"123.45A6\":" << std::endl;
	try
	{
		ScalarConverter::convert("123.45A6");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\"123. 456\":" << std::endl;
	try
	{
		ScalarConverter::convert("123. 456");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\"123.456 \":" << std::endl;
	try
	{
		ScalarConverter::convert("123.456 ");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\" 123.456\":" << std::endl;
	try
	{
		ScalarConverter::convert(" 123.456");
	}
	catch ( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Double tests done" << std::endl;
}

void	test( void )
{
	std::cout << ">> Testing the convert function <<" << std::endl;
	try
	{
		char_test();
		int_test();
		float_test();
		double_test();
	}
	catch( const std::exception & e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}	
	