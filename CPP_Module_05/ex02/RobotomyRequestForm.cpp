#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
{
	throw AForm::FormNotProperlyConstructedException();
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &other ) : AForm("RobotomyRequestForm", other.getTarget(), 72, 45)
{
	throw AForm::FormNotProperlyConstructedException();
	*this = other;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", target, 72, 45)
{
	std::srand(std::clock());
	// RobotomyRequestForm constructed
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// RobotomyRequestForm destructed
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "Performing robotomy on " << this->getTarget() << ":" << std::endl;
		std::cout << "*drilling noises*" << std::endl;
		if (rand() % 2)
			std::cout << this->getTarget() << " was robotomized succesfully!" << std::endl;
		else
			std::cout << "The robotomy failed..." << std::endl;
	}
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &other )
{
	if ( this != &other )
	{

	}
	return *this;
}
