#include <iostream>
#include <stdarg.h>
#include <sstream>

void	log( const char *format, ... )
{
	std::ostringstream	oss;
	va_list	args;
	va_start(args, format);
	while (*format)
	{
		oss << *format;
		format++;
	}
	std::cout << oss.str() << std::endl;
	va_end(args);
}
