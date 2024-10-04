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

	}
	return *this;
}

// Doesn't work either but it's surprisingly simpler than whatever I was doing
void	RPN::easyRPN( std::string const & expression )
{
	std::deque<t_token>	tokenized_expression = tokenize(expression);
	printDeque(tokenized_expression);
	std::deque<int> stack;

	for (size_t i = 0; i < tokenized_expression.size(); i++)
	{
		if (tokenized_expression[i].flag == NUMBER)
			stack.push_back(tokenized_expression[i].value);
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
			if (tokenized_expression[i].flag == ADD)
				stack.push_back(operand1 + operand2);
			else if (tokenized_expression[i].flag == SUB)
				stack.push_back(operand1 - operand2);
			else if (tokenized_expression[i].flag == MUL)
				stack.push_back(operand1 * operand2);
			else if (tokenized_expression[i].flag == DIV)
				stack.push_back(operand1 / operand2);
		}
	}
	std::cout << stack.back() << std::endl;
}

void	RPN::calculate( std::string const & expression )
{
	if (verifyExpression(expression) == false)
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	easyRPN(expression);
	return ;
	std::deque<t_token>	tokenized_expression = tokenize(expression);

	//////////// debug
	std::deque<t_token>::const_iterator it2 = tokenized_expression.begin();
	int	numbers = 0;
	int	operators = 0;
	int	flag = 0;
	while (it2 != tokenized_expression.end())
	{
		if (it2->flag == NUMBER)
		{
			numbers++;
			if (flag == NUMBER)
			{

			}
			flag = NUMBER;
		}
		else
		{
			operators++;
			if (flag == NUMBER)
			{
				
			}
			flag = 0;
		}
		it2++;
	}
	std::cout << "Numbers: " << numbers << std::endl;
	std::cout << "Operators: " << operators << std::endl;
	//////////////

	size_t	i = 0;
	while (tokenized_expression.size() > 1)
	{
		std::deque<t_token>	sub_expression = getSubExpression(tokenized_expression);
		int					result = operateSubExpression(sub_expression);
		t_token				token;
		token.value = result;
		token.flag = 0;
		tokenized_expression.push_front(token);
		i++;
	}
	std::cout << tokenized_expression.front().value << std::endl;
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
			token.flag = 0;
		}
		tokenized_expression.push_back(token);
	}
	return tokenized_expression;
}

std::deque<t_token>	RPN::getSubExpression( std::deque<t_token> & tokenized_expression )
{
	// std::cout << "GetSubExpression Function:" << std::endl;
	std::deque<t_token>	sub_expression;
	// printDeque(tokenized_expression);

	std::deque<t_token>::const_iterator it = tokenized_expression.begin();
	bool	reached_operator = false;
	while (it != tokenized_expression.end())
	{
		if (it->flag == NUMBER) 
		{
			if (reached_operator == true)
				break ;
			sub_expression.push_back(*it);
			tokenized_expression.pop_front();
		}
		else // OPERATOR
		{
			reached_operator = true;
			sub_expression.push_back(*it);
			tokenized_expression.pop_front();
		}
		it++;
	}
	// std::cout << "Resulting expression:" << std::endl;
	// printDeque(sub_expression);
	// std::cout << "Resulting original expression:" << std::endl;
	// printDeque(tokenized_expression);
	// std::cout << "GetSubExpression Function over" << std::endl;
	return sub_expression;
}

int	RPN::operateSubExpression( std::deque<t_token> & sub_expression )
{
	// std::cout << "OperateSubExpression Function:" << std::endl;
	// std::cout << "Entered:" << std::endl;
	// printDeque(sub_expression);
	std::deque<t_token>	ordered_expression;

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
	// std::cout << "Ordered Expression:" << std::endl;
	// printDeque(ordered_expression);
	std::deque<t_token>::iterator it = ordered_expression.begin();
	int	operandLeft = it->value;
	int	operandRight = 0;
	int	operator_flag = 0;
	it++;
	// size_t	i = 1;
	while (it != ordered_expression.end())
	{
		// std::cout << "Checking: " << it->value << std::endl;
		if (it->flag == NUMBER)
		{
			// std::cout << "Is digit" << std::endl;
			operandRight = it->value;
			// std::cout << "(" << operandLeft << " " << static_cast<char>(operator_flag) << " " << operandRight << ") " << std::endl;
			if (operator_flag == ADD)
				operandLeft = operandRight + operandLeft;
			else if (operator_flag == SUB)
				operandLeft = operandRight - operandLeft;
			else if (operator_flag == MUL)
				operandLeft = operandRight * operandLeft;
			else if (operator_flag == DIV)
				operandLeft = operandRight / operandLeft;
			// std::cout << "Current result: " << operandLeft << std::endl;
		}
		else
		{
			// std::cout << "Is operator" << std::endl;
			operator_flag = it->flag;
		}
		it++;
	}
	// std::cout << "Result = " << operandLeft << std::endl;
	// std::cout << "OperateSubExpression Function over" << std::endl;
	return operandLeft;
}

void	RPN::printDeque( std::deque<t_token> const & deque )
{
	std::deque<t_token>::const_iterator it = deque.begin();
	while (it != deque.end())
	{
		if (it->flag == NUMBER)
			std::cout << it->value << " ";
		else
			std::cout << static_cast<char>(it->value) << " ";
		it++;
	}
	std::cout << std::endl;
}