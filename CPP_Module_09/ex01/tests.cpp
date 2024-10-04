#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <sstream>
#include <cstring>

#include <list>
#include <vector>
#include <deque>
#include <map>

void	testVerifyExpression( void );
void	testTokenize( void );

int	main(void)
{
	// testVerifyExpression();
	testTokenize();
	return 0;
}

void	tokenize( std::string const & expression )
{
	std::string token;

	std::istringstream iss(expression);
	std::cout << "Tokenizing: " << expression << std::endl;
	while (iss >> token)
	{
		std::cout << "Token: " << token << std::endl;
	}
	std::cout << "Tokens over" << std::endl;
	return ;
}

void	testTokenize( void )
{
	std::string expression1 = "8 9 * 9 - 9 - 9 - 4 - 1 +";
	std::string expression2 = "7 7 * 7 -";
	std::string expression3 = "1 2 * 2 / 2 * 2 4 - +";
	std::string	expression4 = "4 8 + 1 3 + /";
	std::string expression5 = "2 6 2 4 * + /";
	std::string expression6 = "4 2 5 * + 1 3 2 * + /";

	tokenize(expression1);
	tokenize(expression2);
	tokenize(expression3);
	tokenize(expression4);
	tokenize(expression5);
	tokenize(expression6);
}

bool	verifyExpression( std::string const & expression )
{
	std::cout << "Verifying expression: \"" << expression << "\"" << std::endl;
	std::string::const_iterator it = expression.begin();
	std::string operators = "+-*/";
	std::string numbers = "0123456789";
	std::string valid_chars = operators + numbers;

	size_t	i = 0;
	while (it != expression.end())
	{
		// std::cout << "it: " << *it << std::endl;
		// std::cout << "i: " << i << std::endl;
		if (i % 2 == 0)
		{
			if (valid_chars.find(*it) == std::string::npos)
			{
				std::cout << "Invalid character: " << *it << std::endl;
				return false;
			}
		}
		else if (i % 2 != 0)
		{
			if (*it != ' ')
			{
				std::cout << "Invalid character: " << *it << std::endl;
				return false;
			}
		}
		it++;
		i++;
	}
	std::cout << "Expression is valid." << std::endl;
	return true;
}

void	testVerifyExpression( void )
{
	std::string expression1 = "8 9 * 9 - 9 - 9 - 4 - 1 +";
	std::string expression2 = "7 7 * 7 -";
	std::string expression3 = "1 2 * 2 / 2 * 2 4 - +";
	std::string	expression4 = "4 8 + 1 3 + /";
	std::string expression5 = "2 6 2 4 * + /";
	std::string expression6 = "4 2 5 * + 1 3 2 * + /";
	std::string expression = "(1 + 2) * 3";

	verifyExpression(expression1);
	verifyExpression(expression2);
	verifyExpression(expression3);
	verifyExpression(expression4);
	verifyExpression(expression5);
	verifyExpression(expression6);
	verifyExpression(expression);
}
