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

void	RPN::calculate( std::string const &expression )
{
	std::deque<std::string> tokens = this->tokenize(expression);
	std::deque<std::string> postfix = this->toPostfix(tokens);
	std::deque<std::string> result = this->evaluate(postfix);
	this->printResult(result);
}

std::deque<std::string>	RPN::tokenize( std::string const &expression )
{
	std::deque<std::string> tokens;
	std::string token;
	std::string::const_iterator it = expression.begin();
	while (it != expression.end())
	{
		if (std::isspace(*it))
		{
			if (!token.empty())
			{
				tokens.push_back(token);
				token.clear();
			}
		}
		else
		{
			token += *it;
		}
		++it;
	}
	if (!token.empty())
	{
		tokens.push_back(token);
	}
	return tokens;
}

std::deque<std::string>	RPN::toPostfix( std::deque<std::string> const &tokens )
{
	std::deque<std::string> postfix;
	std::deque<std::string> stack;
	std::map<std::string, int> precedence;
	precedence["+"] = 1;
	precedence["-"] = 1;
	precedence["*"] = 2;
	precedence["/"] = 2;
	precedence["("] = 0;
	std::deque<std::string>::const_iterator it = tokens.begin();
	while (it != tokens.end())
	{
		if (std::isdigit((*it)[0]))
		{
			postfix.push_back(*it);
		}
		else if (*it == "(")
		{
			stack.push_back(*it);
		}
		else if (*it == ")")
		{
			while (!stack.empty() && stack.back() != "(")
			{
				postfix.push_back(stack.back());
				stack.pop_back();
			}
			stack.pop_back();
		}
		else
		{
			while (!stack.empty() && precedence[*it] <= precedence[stack.back()])
			{
				postfix.push_back(stack.back());
				stack.pop_back();
			}
			stack.push_back(*it);
		}
		++it;
	}
	while (!stack.empty())
	{
		postfix.push_back(stack.back());
		stack.pop_back();
	}
	return postfix;
}

std::deque<std::string>	RPN::evaluate( std::deque<std::string> const &postfix )
{
	std::deque<std::string> result;
	std::deque<std::string> stack;
	std::deque<std::string>::const_iterator it = postfix.begin();
	while (it != postfix.end())
	{
		if (std::isdigit((*it)[0]))
		{
			stack.push_back(*it);
		}
		else
		{
			double b = atof(stack.back().c_str());
			stack.pop_back();
			double a = atof(stack.back().c_str());
			stack.pop_back();
			double c;
			if (*it == "+")
			{
				c = a + b;
			}
			else if (*it == "-")
			{
				c = a - b;
			}
			else if (*it == "*")
			{
				c = a * b;
			}
			else if (*it == "/")
			{
				c = a / b;
			}
			else
			{
				throw std::runtime_error("Invalid operator");
			}
			std::ostringstream oss;
			oss << c;
			stack.push_back(oss.str());
		}
		++it;
	}
	result.push_back(stack.back());
	return result;
}

void	RPN::printResult( std::deque<std::string> const &result )
{
	std::cout << "Result: " << result.front() << std::endl;
}

