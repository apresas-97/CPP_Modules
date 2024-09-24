#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>

template<typename T>
void	print( T & element )
{
	std::cout << element << std::endl;
}

// template specialization for bool
template<>
void	print<bool>( bool & element )
{
	std::cout << (element ? "true" : "false") << std::endl;
}

// template specialization for char
template<>
void	print<char>( char & element )
{
	if (std::isprint(element))
		std::cout << "'" << element << "'" << std::endl;
	else
		std::cout << "'Non displayable'" << std::endl;
}

#endif // FUNCTIONS_HPP