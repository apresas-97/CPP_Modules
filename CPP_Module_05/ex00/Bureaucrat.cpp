#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name( "bureauman" ), _grade( 0 )
{
	std::cout << "Bureaucrat created with default name and grade 1" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name( name )
{
	
}

Bureaucrat::Bureaucrat( Bureaucrat const & src )
{
	*this = src;
}

Bureaucrat::~Bureaucrat( void )
{

}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & other )
{
	if ( this != &other )
		//
	return *this;
}

std::ostream & operator<<( std::ostream & out, const Bureaucrat & rhs )
{
	// out << rhs.something;
}
