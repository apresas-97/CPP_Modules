#include "RPN.hpp"
#include <iostream>
#include <string>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

void	test_rpn( void );

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN \"expression\"" << std::endl;
		return 1;
	}

	std::string expression = argv[1];
	if (expression == "test")
	{
		test_rpn();
		return 0;
	}

	RPN rpn;
	rpn.calculate(expression);

	return 0;
}

void	test_expression( std::string const & expression, std::string const & expected_result )
{
	RPN rpn;
	std::cout << "Expression: \"" << expression << "\"" << std::endl;
	std::cout << "Expected result:\n" << expected_result << std::endl;
	rpn.calculate(expression);
	std::cout << std::endl;
	return ;
}

void	test_rpn( void )
{
	RPN rpn;
	std::cout << GREEN "VALID EXPRESSIONS" RESET << std::endl;
	// You can use https://paodayag.dev/reverse-polish-notation-js-parser/ to verify the results
	// 8 9 * 9 - 9 - 9 - 4 - 1 +
	test_expression("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	// 7 7 * 7 -
	test_expression("7 7 * 7 -", "42");
	// 1 2 * 2 / 2 * 2 4 - +
	test_expression("1 2 * 2 / 2 * 2 4 - +", "0");
	// 2 3 7 * 8 5 3 6 2 + * 4 - 3 7 + / + - * *
	test_expression("2 3 7 * 8 5 3 6 2 + * 4 - 3 7 + / + - * *", "42");
	// 1 2 3 4 5 6 7 8 9 + - + - + - + - 9 8 7 6 5 4 3 2 1 - + - + - + - + -
	test_expression("1 2 3 4 5 6 7 8 9 + - + - + - + - 9 8 7 6 5 4 3 2 1 - + - + - + - + -", "0");
	// 4 2 5 * + 1 3 2 * + / 8 5 + + 2 1 * *
	test_expression("4 2 5 * + 1 3 2 * + / 8 5 + + 2 1 * *" , "30");
	// 3 2 3 2 2 * + * * 7 2 * - 6 2 4 * + /
	test_expression("3 2 3 2 2 * + * * 7 2 * - 6 2 4 * + /", "2");
	// 2 5 6 3 / 8 * - + 3 - 3 * 5 4 + * 9 /
	test_expression("2 5 6 3 / 8 * - + 3 - 3 * 5 4 + * 9 /", "-36");
	// 2 2 * 3 + 5 * 4 -
	test_expression("2 2 * 3 + 5 * 4 -", "31");
	// 3 2 3 2 2 * + * * 7 2 * -
	test_expression("3 2 3 2 2 * + * * 7 2 * -", "28");
	// 1
	test_expression("1", "1");

	std::cout << RED "INVALID EXPRESSIONS" RESET << std::endl;
	test_expression("10", "Error | Because 10 > 9");
	test_expression("28 6 2 4 * + /", "Error | Because 28 > 9");
	test_expression("", "Error | Because empty expression");
	// 	
	test_expression("+", "Error | Because bad formulation");
	// 1 1
	test_expression("1 1", "Error | Because bad formulation");
	// 1 1 + +
	test_expression("1 1 + +", "Error | Because bad formulation");
	// 4 2 5 * + 1 3 2 * * + / 8 5 + + 2 1 * *
	test_expression("4 2 5 * + 1 3 2 * * + / 8 5 + + 2 1 * *" , "Error | Because bad formulation");
	// 2 3 7 * 8 5 3 6 2 + * 4 - 2 3 7 + / + - * *
	test_expression("2 3 7 * 8 5 3 6 2 + * 4 - 2 3 7 + / + - * *" , "Error | Because bad formulation");
	// 9 9 - 8 2 3 + * 5 2 2 2 * * * - /
	test_expression("9 9 - 8 2 3 + * 5 2 2 2 * * * - /", "Error (division by zero found)");
	// 5 0 /
	test_expression("5 0 /", "Error (division by zero found)");
	return ;
}
