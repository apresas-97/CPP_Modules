#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base
{
	public:
		virtual ~Base();

		static Base	*generate( void );
		static void	identify( Base *p );
		static void	identify( Base &p );

	private:

};

#endif // BASE_HPP
