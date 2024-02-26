#include "Fixed.hpp"
#include <iostream>
#include <string>

#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BOLD "\x1b[1m"
#define REG "\x1b[0m"

int	main( void )
{
	std::string input;
	Fixed a;

	std::cout << BOLD << "| Testing " << GREEN << "++" << REG << BOLD << " operation: |" << REG << std::endl;

	std::cout << "  a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "  a = " << a << std::endl;
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << GREEN << "--" << REG << BOLD << " operation: |" << REG << std::endl;

	std::cout << "  a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "  a = " << a << std::endl;
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << BLUE << "+" << REG << BOLD << " operation: |" << REG << std::endl;

	Fixed lhs;
	Fixed rhs;

	lhs = 1;
	rhs = 1;
	std::cout << lhs << " + " << rhs << " = " << lhs + rhs << std::endl;
	lhs = 3;
	rhs = 4;
	std::cout << lhs << " + " << rhs << " = " << lhs + rhs << std::endl;
	lhs = 0.35f;
	rhs = 9.65f;
	std::cout << lhs << " + " << rhs << " = " << lhs + rhs << std::endl;
	lhs = -5.1f;
	rhs = 3;
	std::cout << lhs << " + " << rhs << " = " << lhs + rhs << std::endl;
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << BLUE << "-" << REG << BOLD << " operation: |" << REG << std::endl;
	
	lhs = 1;
	rhs = 1;
	std::cout << lhs << " - " << rhs << " = " << lhs - rhs << std::endl;
	lhs = 100;
	rhs = 58;
	std::cout << lhs << " - " << rhs << " = " << lhs - rhs << std::endl;
	lhs = -10.5f;
	rhs = 5;
	std::cout << lhs << " - " << rhs << " = " << lhs - rhs << std::endl;
	lhs = 4;
	rhs = -6;
	std::cout << lhs << " - " << rhs << " = " << lhs - rhs << std::endl;
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << BLUE << "*" << REG << BOLD << " operation: |" << REG << std::endl;

	lhs = 2;
	rhs = 4;
	std::cout << lhs << " * " << rhs << " = " << lhs * rhs << std::endl;
	lhs = 8;
	rhs = 8;
	std::cout << lhs << " * " << rhs << " = " << lhs * rhs << std::endl;
	lhs = 315.55f;
	rhs = 105.49f;
	std::cout << lhs << " * " << rhs << " = " << lhs * rhs << std::endl;
	lhs = -4;
	rhs = 25;
	std::cout << lhs << " * " << rhs << " = " << lhs * rhs << std::endl;
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << BLUE << "/" << REG << BOLD << " operation: |" << REG << std::endl;

	lhs = 5;
	rhs = 2;
	std::cout << lhs << " / " << rhs << " = " << lhs / rhs << std::endl;
	lhs = 4.242f;
	rhs = 1.5f;
	std::cout << lhs << " / " << rhs << " = " << lhs / rhs << std::endl;
	lhs = 74.51f;
	rhs = 11.05f;
	std::cout << lhs << " / " << rhs << " = " << lhs / rhs << std::endl;
	lhs = 32768;
	lhs--;
	rhs = 0;
	rhs++;
	std::cout << lhs << " / " << rhs << " = " << lhs / rhs << std::endl;
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << RED << ">" << REG << BOLD << " operation: |" << REG << std::endl;

	lhs = 1;
	rhs = 1;
	std::cout << lhs << " > " << rhs << " ? " << (lhs > rhs) << std::endl;
	lhs = 42;
	rhs = 43;
	std::cout << lhs << " > " << rhs << " ? " << (lhs > rhs) << std::endl;
	lhs = 0;
	lhs++;
	rhs = 0;
	std::cout << lhs << " > " << rhs << " ? " << (lhs > rhs) << std::endl;
	lhs = 0;
	lhs--;
	rhs = 0;
	std::cout << lhs << " > " << rhs << " ? " << (lhs > rhs) << std::endl;
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << RED << "<" << REG << BOLD << " operation: |" << REG << std::endl;

	lhs = 1;
	rhs = 1;
	std::cout << lhs << " < " << rhs << " ? " << (lhs < rhs) << std::endl;
	lhs = 42;
	rhs = 43;
	std::cout << lhs << " < " << rhs << " ? " << (lhs < rhs) << std::endl;
	lhs = 0;
	lhs++;
	rhs = 0;
	std::cout << lhs << " < " << rhs << " ? " << (lhs < rhs) << std::endl;
	lhs = 0;
	lhs--;
	rhs = 0;
	std::cout << lhs << " < " << rhs << " ? " << (lhs < rhs) << std::endl;
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << RED << ">=" << REG << BOLD << " operation: |" << REG << std::endl;

	lhs = 1;
	rhs = 1;
	std::cout << lhs << " >= " << rhs << " ? " << (lhs >= rhs) << std::endl;
	lhs = 42;
	rhs = 43;
	std::cout << lhs << " >= " << rhs << " ? " << (lhs >= rhs) << std::endl;
	lhs = 0;
	lhs++;
	rhs = 0;
	std::cout << lhs << " >= " << rhs << " ? " << (lhs >= rhs) << std::endl;
	lhs = 0;
	lhs--;
	rhs = 0;
	std::cout << lhs << " >= " << rhs << " ? " << (lhs >= rhs) << std::endl;
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << RED << "<=" << REG << BOLD << " operation: |" << REG << std::endl;

	lhs = 1;
	rhs = 1;
	std::cout << lhs << " <= " << rhs << " ? " << (lhs <= rhs) << std::endl;
	lhs = 42;
	rhs = 43;
	std::cout << lhs << " <= " << rhs << " ? " << (lhs <= rhs) << std::endl;
	lhs = 0;
	lhs++;
	rhs = 0;
	std::cout << lhs << " <= " << rhs << " ? " << (lhs <= rhs) << std::endl;
	lhs = 0;
	lhs--;
	rhs = 0;
	std::cout << lhs << " <= " << rhs << " ? " << (lhs <= rhs) << std::endl;
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << RED << "==" << REG << BOLD << " operation: |" << REG << std::endl;

	lhs = 1;
	rhs = 1;
	std::cout << lhs << " == " << rhs << " ? " << (lhs == rhs) << std::endl;
	lhs = 42;
	rhs = 43;
	std::cout << lhs << " == " << rhs << " ? " << (lhs == rhs) << std::endl;
	lhs = 0;
	lhs++;
	rhs = 0;
	std::cout << lhs << " == " << rhs << " ? " << (lhs == rhs) << std::endl;
	lhs = 0;
	lhs--;
	rhs = 0;
	std::cout << lhs << " == " << rhs << " ? " << (lhs == rhs) << std::endl;
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << RED << "!=" << REG << BOLD << " operation: |" << REG << std::endl;

	lhs = 1;
	rhs = 1;
	std::cout << lhs << " != " << rhs << " ? " << (lhs != rhs) << std::endl;
	lhs = 42;
	rhs = 43;
	std::cout << lhs << " != " << rhs << " ? " << (lhs != rhs) << std::endl;
	lhs = 0;
	lhs++;
	rhs = 0;
	std::cout << lhs << " != " << rhs << " ? " << (lhs != rhs) << std::endl;
	lhs = 0;
	lhs--;
	rhs = 0;
	std::cout << lhs << " != " << rhs << " ? " << (lhs != rhs) << std::endl;
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << YELLOW << "min()" << REG << BOLD << " operation: |" << REG << std::endl;

	lhs = 54;
	rhs = 25;
	std::cout << "min( " << lhs << ", " << rhs << " ) returns: " << Fixed::min( lhs, rhs ) << std::endl; 
	lhs = 0;
	lhs++;
	rhs = 0;
	std::cout << "min( " << lhs << ", " << rhs << " ) returns: " << Fixed::min( lhs, rhs ) << std::endl; 
	lhs = 75013;
	rhs = 13853;
	std::cout << "min( " << lhs << ", " << rhs << " ) returns: " << Fixed::min( lhs, rhs ) << std::endl; 
	std::cout << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::getline(std::cin, input);
	std::cout << "\x1b[2A" << std::endl;

	std::cout << BOLD << "| Testing " << YELLOW << "max()" << REG << BOLD << " operation: |" << REG << std::endl;

	lhs = 54;
	rhs = 25;
	std::cout << "max( " << lhs << ", " << rhs << " ) returns: " << Fixed::max( lhs, rhs ) << std::endl; 
	lhs = 0;
	lhs++;
	rhs = 0;
	std::cout << "max( " << lhs << ", " << rhs << " ) returns: " << Fixed::max( lhs, rhs ) << std::endl; 
	lhs = 75013;
	rhs = 13853;
	std::cout << "max( " << lhs << ", " << rhs << " ) returns: " << Fixed::max( lhs, rhs ) << std::endl; 

	return 0;
}
