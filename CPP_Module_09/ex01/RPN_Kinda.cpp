#include "RPN.hpp"

//////////////////////// utils
void	print_dequee( std::deque<int> const & deque )
{
	std::deque<int>::const_iterator it = deque.begin();
	while (it != deque.end())
	{
		if (*it == ADD)
			std::cout << "+ ";
		else if (*it == SUB)
			std::cout << "- ";
		else if (*it == MUL)
			std::cout << "* ";
		else if (*it == DIV)
			std::cout << "/ ";
		else
			std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	print_dequee( std::deque<char> const & deque )
{
	std::deque<char>::const_iterator it = deque.begin();
	while (it != deque.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
////////////////////

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

	}
	return *this;
}

void	RPN::calculate( std::string const & expression )
{
	if (verifyExpression(expression) == false)
	{
		std::cout << "Error" << std::endl;
		return;
	}
	// std::deque<int>	tokenized_expression = tokenize(expression);
	// std::cout << "tokenize complete" << std::endl;
	// std::deque<int>	sub_expression = getSubExpression(tokenized_expression);
	// std::cout << "getSubExpression complete" << std::endl;

	// operateSubExpression(sub_expression);
	newApproach(expression);
	
	// simpleApproach(expression);
	// std::deque<std::string> deque = tokenize(expression);
	// calculateAndPrint(deque);
}

void	RPN::newApproach( std::string const & expression )
{
	std::deque<char>	tokenized_expression = tokenize(expression);
	std::deque<int>		results;
	int					leftmost_value = 0;

	int i = 0;
	while (tokenized_expression.size() > 1)
	{
		std::cout << "Loop!" << std::endl;
		std::cout << "Tokenized expression:" << std::endl;
		print_dequee(tokenized_expression);

		std::deque<char>	sub_expression = getSubExpression(tokenized_expression);
		std::cout << "Sub expression:" << std::endl;
		print_dequee(sub_expression);

		leftmost_value = operateSubExpression(sub_expression, leftmost_value);
		// tokenized_expression.push_front(result);
		std::cout << "Leftmost value: " << leftmost_value << std::endl;
		i++;
		if (i == 10)
			break ;
	}
	std::cout << "Result: " << tokenized_expression.front() << std::endl;
}

int	RPN::operateSubExpression( std::deque<char> & sub_expression, int leftmost_value )
{
	std::cout << "OperateSubExpression Function:" << std::endl;
	std::cout << "Entered:" << std::endl;
	print_dequee(sub_expression);
	std::deque<char>	ordered_expression;

	size_t	size = sub_expression.size();
	for (size_t i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			ordered_expression.push_front(sub_expression.front());
			sub_expression.pop_front();
		}
		else
		{
			ordered_expression.push_front(sub_expression.back());
			sub_expression.pop_back();
		}
	}
	print_dequee(ordered_expression);
	std::deque<char>::iterator it = ordered_expression.begin();
	int	operandLeft = *it - '0';
	int	operandRight = 0;
	int	operator_flag = 0;
	it++;
	size_t	i = 1;
	while (it != ordered_expression.end())
	{
		std::cout << "Checking: " << static_cast<char>(*it) << std::endl;
		if (i % 2 == 0)
		{
			std::cout << "Is digit" << std::endl;
			operandRight = *it - '0';
			if (operator_flag == '+')
				operandLeft = operandLeft + operandRight;
			else if (operator_flag == '-')
				operandLeft = operandLeft - operandRight;
			else if (operator_flag == '*')
				operandLeft = operandLeft * operandRight;
			else if (operator_flag == '/')
				operandLeft = operandLeft / operandRight;
		}
		else
		{
			std::cout << "Is operator" << std::endl;
			operator_flag = *it;
		}
		i++;
		it++;
	}
	if (leftmost_value == 0)
	std::cout << "Result = " << operandLeft << std::endl;
	std::cout << "OperateSubExpression Function over" << std::endl;
	return operandLeft;
}

bool	RPN::verifyExpression( std::string const & expression )
{
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

std::deque<char> RPN::tokenize( std::string const & expression )
{
	std::deque<char>		tokenized_expression;
	char					token;
	std::istringstream		iss(expression);

	while (iss >> token)
	{
		tokenized_expression.push_back(token);
	}
	return tokenized_expression;
}

std::deque<char>	RPN::getSubExpression( std::deque<char> & tokenized_expression )
{
	std::cout << "GetSubExpression Function:" << std::endl;
	std::deque<char>	sub_expression;

	std::deque<char>::const_iterator it = tokenized_expression.begin();
	bool	reached_operator = false;
	int	numbers = 0;
	int	operators = 0;
	while (it != tokenized_expression.end())
	{
		if (std::isdigit(*it))
		{
			numbers++;
			if (reached_operator == true)
				break ;
			sub_expression.push_back(*it);
			tokenized_expression.pop_front();
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			operators++;
			reached_operator = true;
			std::cout << "Operators: " << operators << std::endl;
			std::cout << "Numbers: " << numbers << std::endl;
			if (operators == numbers)
				break ;
			sub_expression.push_back(*it);
			tokenized_expression.pop_front();
		}
		it++;
	}
	std::cout << "GetSubExpression Function over" << std::endl;
	return sub_expression;
}

// std::deque<std::string> RPN::tokenize( std::string const & expression )
// {
// 	std::deque<std::string> tokens;
// 	std::string token;

// 	std::istringstream iss(expression);
// 	while (iss >> token)
// 	{
// 		tokens.push_back(token);
// 	}
// 	return tokens;
// }

// void	RPN::calculateAndPrint( std::deque<std::string> & deque )
// {
// 	std::deque<std::string>::iterator	it = deque.begin();
// 	unsigned int operand1 = 0;
// 	unsigned int operand2 = 0;
// 	while (it != deque.end())
// 	{
// 		if (std::isdigit((*it)[0]) == 1)
// 		{
// 			// operand1 = std::stoi(*it);
// 		}
// 		else
// 		{
// 			// operand2 = std::stoi(*it);
// 			if (*it == "+")
// 				operand1 += operand2;
// 			else if (*it == "-")
// 				operand1 -= operand2;
// 			else if (*it == "*")
// 				operand1 *= operand2;
// 			else if (*it == "/")
// 				operand1 /= operand2;
// 		}
// 		it++;
// 	}
// }

void	RPN::simpleApproach( std::string const & expression )
{
	std::deque<int>	deque;
	std::istringstream	iss(expression);
	char	token = 0;
	while (iss >> token)
	{
		// std::cout << "Token: " << token << std::endl;
		if (std::isspace(token))
		{
			// std::cout << "Check isspace" << std::endl;
			continue ;
		}
		else if (std::isdigit(token))
		{
			// std::cout << "Check isdigit" << std::endl;
			deque.push_back(token - '0');
			// std::cout << "Check push_back" << std::endl;
		}
		else
		{
			// std::cout << "Check operator" << std::endl;
			int	operand2 = deque.back();
			// std::cout << "Check deque.back" << std::endl;
			deque.pop_back();
			// std::cout << "Check pop_back" << std::endl;
			int	operand1 = deque.back();
			// std::cout << "Check deque.back" << std::endl;
			deque.pop_back();
			// std::cout << "Check pop_back" << std::endl;

			if (token == '+')
				deque.push_back(operand1 + operand2);
			else if (token == '-')
				deque.push_back(operand1 - operand2);
			else if (token == '*')
				deque.push_back(operand1 * operand2);
			else if (token == '/')
				deque.push_back(operand1 / operand2);
			else
				throw std::runtime_error("What the hell happened?");
		}
		// std::cout << "Check looped" << std::endl;
	}
	std::cout << deque.front() << std::endl;
}
