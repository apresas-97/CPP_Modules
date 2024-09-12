#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name( "bureauman" ), _grade( 0 )
{
	std::cout << "Bureaucrat created with default name and grade 1" << std::endl;
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

Bureaucrat::Bureaucrat( Bureaucrat const & src )
{
	*this = src;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destroyed: " << *this << std::endl;
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & other )
{
	if ( this != &other )
		this->_grade = other.getGrade();
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
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade( void )
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream & operator<<( std::ostream & out, const Bureaucrat & rhs )
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}
