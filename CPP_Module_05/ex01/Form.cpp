#include "Form.hpp"

Form::Form( void ) : _name( "SomeForm" ), _gradeToSign(1), _gradeToExecute(1)
{
	this->_signed = false;
	std::cout << "Form default constructed: " << *this << std::endl;
}

Form::Form( std::string name, int gradeToSign, int gradeToExecute ) : _name( name ), _gradeToSign( gradeToSign ), _gradeToExecute( gradeToExecute )
{
	this->_signed = false;
	std::cout << "Form constructed: " << *this << std::endl;
}

Form::Form( Form const &other ) : _name( other.getName() ), _gradeToSign( other.getGradeToSign() ), _gradeToExecute( other.getGradeToExecute() )
{
	*this = other;
	std::cout << "Form copy constructed:" << *this << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructed: " << *this << std::endl;
}

Form &Form::operator=( Form const &other )
{
	if ( this != &other )
	{
		// Copying forms makes no sense
	}
	return *this;
}

std::string	Form::getName( void ) const
{
	return _name;
}

bool	Form::getSigned( void ) const
{
	return _signed;
}

int		Form::getGradeToSign( void ) const
{
	return _gradeToSign;
}

int		Form::getGradeToExecute( void ) const
{
	return _gradeToExecute;
}

void	Form::beSigned( Bureaucrat &bureaucrat )
{
	if ( bureaucrat.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

// ?
std::ostream &	operator<<( std::ostream & out, Form const & rhs )
{
	out << "Form " << rhs.getName() << " is ";
	if (rhs.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << ", requires grade " << rhs.getGradeToSign() << " to sign and grade " << rhs.getGradeToExecute() << " to execute";
	return out;
}
