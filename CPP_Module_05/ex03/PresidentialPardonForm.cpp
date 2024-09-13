#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
{
	throw AForm::FormNotProperlyConstructedException();
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &other ) : AForm("PresidentialPardonForm", other.getTarget(), 25, 5)
{
	throw AForm::FormNotProperlyConstructedException();
	*this = other;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", target, 25, 5)
{
	// PresidentialPardonForm constructed
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// PresidentialPardonForm destructed
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if ( this->_signed == false )
		throw AForm::FormNotSignedException();
	else if ( executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}

AForm*	PresidentialPardonForm::clone( std::string target ) const
{
	return new PresidentialPardonForm("PresidentialPardonForm", target, 25, 5);
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &other )
{
	if ( this != &other )
	{
		// Contracts are unique, they can't be copied. This has no effect.
	}
	return *this;
}
