#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name( "bureauman" ), _grade( 1 )
{
	std::cout << "Bureaucrat created with default values: " << *this << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name( name )
{
	if ( grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	else if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << "Bureaucrat constructed: " << *this << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name( src.getName() )
{
	*this = src;
	std::cout << "Bureaucrat copy constructed: " << *this << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destroyed: " << *this << std::endl;
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & other )
{
	if ( this != &other )
	{
		this->_grade = other.getGrade();
	}
	return *this;
}

std::string	Bureaucrat::getName( void ) const
{
	return this->_name;
}

int	Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade( void )
{
	// std::cout << "Incrementing grade" << std::endl;
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	// std::cout << "Decrementing grade" << std::endl;
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm( Form & formToSign )
{
	try
	{
		formToSign.beSigned( *this );
	}
	catch ( std::exception & e )
	{
		std::cout << "<" << *this << ">" << " couldn't sign " << "<" << formToSign << ">" << " because: " << e.what() << std::endl;
		return ;
	}

	std::cout << "<" << *this << ">" << " signed " << "<" << formToSign << ">" << std::endl;
}

std::ostream & operator<<( std::ostream & out, const Bureaucrat & rhs )
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
