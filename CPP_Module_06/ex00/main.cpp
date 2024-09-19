#include "ScalarConverter.hpp"

int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "Usage: ./scalar_converter <input>" << std::endl;
		return 1;
	}
	// std::cout << "debug::argv[1] = " << argv[1] << std::endl;

	std::string input = argv[1];

	// try
	// {
	// 	ScalarConverter::convert(input);
	// }
	// catch ( std::exception & e )
	// {
	// 	std::cout << "Exception caught: " << e.what() << std::endl;
	// 	return 1;
	// }

	std::cout << ">> Testing the convert function <<" << std::endl;
	std::cout << "CHARS:" << std::endl;
	ScalarConverter::convert("a");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("1");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert(" ");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("!");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("0");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("9");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("z");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("A");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("Z");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("~");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert(".");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("]");	
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "INTS:" << std::endl;
	ScalarConverter::convert("00");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("-00000000000000000000000000000000000000000000000001");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("42");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("255");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("256");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("2147483647");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("2147483648"); // Invalid
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("-2147483649"); // Invalid
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "FLOATS:" << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("0.042f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("42.42f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("518451.093f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("-0.0f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("-00000000000.123f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("2147483647.0f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("-2147483648.0f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("99999999999999999.0f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("-777777777777777.0f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "DOUBLES:" << std::endl;
	ScalarConverter::convert("0.0");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("0.042");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("42.42");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("784306.74391");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("-000.007");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("+0123.4567");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("+127.0");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Edge cases:" << std::endl;
	std::cout << "Weird ass floats and doubles:" << std::endl;
	ScalarConverter::convert("0.");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("0.f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert(".0");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert(".0f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert(".f");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("+.");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("-.");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("+nan");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("-nan");
	std::cout << "---------------------------------------------" << std::endl;
	ScalarConverter::convert("+1f");
	std::cout << "---------------------------------------------" << std::endl;

	float test = 0.;
	std::cout << "test = " << test << std::endl;

	// // I want to display the bits of a float
	// float f = -2147483584.0f;
	// std::cout << "f = " << f << std::endl;
	// // Now in binary
	// unsigned int *p = reinterpret_cast<unsigned int*>(&f);
	// std::cout << "f in binary: ";
	// for (int i = 31; i >= 0; i--)
	// {
	// 	std::cout << ((*p >> i) & 1);
	// 	if (i % 4 == 0)
	// 		std::cout << " ";
	// }
	// std::cout << std::endl;

	// Now the same for a double
	// double d = -2147483648.1052;
	// std::cout << "d = " << d << std::endl;
	// // Now in binary
	// unsigned long long *q = reinterpret_cast<unsigned long long*>(&d);
	// std::cout << "d in binary: ";
	// for (int i = 63; i >= 0; i--)
	// {
	// 	std::cout << ((*q >> i) & 1);
	// 	if (i % 4 == 0)
	// 		std::cout << " ";
	// }
	// std::cout << std::endl;

	return 0;
}