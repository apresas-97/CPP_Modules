#include "RPN.hpp"

RPN::RPN( void )
{
	// std::cout << "RPN constructor called" << std::endl;
}

RPN::RPN( RPN const &other )
{
	// std::cout << "RPN copy constructor called" << std::endl;
	*this = other;
}

RPN::~RPN()
{
	// std::cout << "RPN destructor called" << std::endl;
}

RPN &RPN::operator=( RPN const &other )
{
	if ( this != &other )
	{
		// Nothing to do here
	}
	return *this;
}

void	RPN::calculate( std::string const & expression )
{
	if (verifyExpressionSyntax(expression) == false)
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	std::deque<int> stack;
	std::deque<t_token>	tokenized_expression = tokenize(expression);

	std::deque<t_token>::const_iterator it = tokenized_expression.begin();
	while (it != tokenized_expression.end())
	{
		if (it->flag == NUMBER)
			stack.push_back(it->value);
		else
		{
			if (stack.size() < 2)
			{
				std::cout << "Error" << std::endl;
				return ;
			}
			int operand2 = stack.back();
			stack.pop_back();
			int operand1 = stack.back();
			stack.pop_back();
			if (it->flag == ADD)
				stack.push_back(operand1 + operand2);
			else if (it->flag == SUB)
				stack.push_back(operand1 - operand2);
			else if (it->flag == MUL)
				stack.push_back(operand1 * operand2);
			else if (it->flag == DIV)
			{
				if (operand2 == 0)
				{
					std::cout << "Error (division by zero found)" << std::endl;
					return ;
				}
				stack.push_back(operand1 / operand2);
			}
		}
		it++;
	}
	if (stack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	std::cout << stack.back() << std::endl;
}

bool	RPN::verifyExpressionSyntax( std::string const & expression )
{
	if (expression.empty())
		return false;
	std::string::const_iterator it = expression.begin();
	std::string valid_characters = "0123456789+-*/";

	size_t	i = 0;
	while (it != expression.end())
	{
		if (i % 2 == 0 && valid_characters.find(*it) == std::string::npos)
			return false;
		else if (i % 2 != 0 && *it != ' ')
			return false;
		it++;
		i++;
	}
	return true;
}

std::deque<t_token> RPN::tokenize( std::string const & expression )
{
	std::deque<t_token>		tokenized_expression;
	t_token					token;
	char					aux_char;
	std::istringstream		iss(expression);
	std::string				operators = "+-*/";

	while (iss >> aux_char)
	{
		token.value = aux_char;
		if (operators.find(aux_char) != std::string::npos)
			token.flag = aux_char;
		else if (std::isdigit(aux_char))
		{
			token.value = aux_char - '0';
			token.flag = NUMBER;
		}
		tokenized_expression.push_back(token);
	}
	return tokenized_expression;
}
