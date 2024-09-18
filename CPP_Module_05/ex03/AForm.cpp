#include "AForm.hpp"

AForm::AForm( void ) : _name( "SomeForm" ), _gradeToSign(1), _gradeToExecute(1)
{
	this->_signed = false;
	std::cout << "Form default constructed: " << *this << std::endl;
}

AForm::AForm( std::string name, std::string target, int gradeToSign, int gradeToExecute ) : _name( name ), _target( target ), _gradeToSign( gradeToSign ), _gradeToExecute( gradeToExecute )
{
	this->_signed = false;
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	std::cout << "Form constructed: " << *this << std::endl;
}

AForm::AForm( AForm const &other ) : _name( other.getName() ), _gradeToSign( other.getGradeToSign() ), _gradeToExecute( other.getGradeToExecute() )
{
	*this = other;
	std::cout << "Form copy constructed:" << *this << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form destructed: " << *this << std::endl;
}

AForm &AForm::operator=( AForm const &other )
{
	if ( this != &other )
	{
		// Copying forms makes no sense
	}
	return *this;
}

std::string	AForm::getName( void ) const
{
	return _name;
}

std::string AForm::getTarget( void ) const
{
	return _target;
}

bool	AForm::getSigned( void ) const
{
	return _signed;
}

int		AForm::getGradeToSign( void ) const
{
	return _gradeToSign;
}

int		AForm::getGradeToExecute( void ) const
{
	return _gradeToExecute;
}

void	AForm::beSigned( Bureaucrat & bureaucrat )
{
	if ( this->_signed == true)
		throw AForm::FormAlreadySignedException();
	else if ( bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

void	AForm::execute( Bureaucrat const & executor ) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "Form executed!" << std::endl;
	}
}

// ?
std::ostream &	operator<<( std::ostream & out, AForm const & rhs )
{
	out << "Form " << rhs.getName() << ", with target \"" << rhs.getTarget() << "\",";
	if (rhs.getSigned())
		out << " (signed)";
	else
		out << " (not signed)";
	out << ", requires grade " << rhs.getGradeToSign() << " to sign and grade " << rhs.getGradeToExecute() << " to execute";
	return out;
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return ("Form is already signed");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

const char* AForm::FormNotProperlyConstructedException::what() const throw()
{
	return ("Form was not properly constructed");
}	

const char* AForm::FileIssueException::what() const throw()
{
	return ("An issue with the file occurred");
}
