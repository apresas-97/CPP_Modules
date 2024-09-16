#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", "home", 145, 137)
{
	throw AForm::FormNotProperlyConstructedException();
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &other ) : AForm("ShrubberyCreationForm", other.getTarget(),145, 137)
{
	throw AForm::FormNotProperlyConstructedException();
	*this = other;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", target, 145, 137)
{
	// ShrubberyCreationForm constructed
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// ShrubberyCreationForm destructed
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "Creating a shrubbery in file " << this->getTarget() << "_shrubbery" << std::endl;
		std::ofstream file;
		std::string filename = this->getTarget() + "_shrubbery";
		file.open(filename.c_str());
		if (file.fail())
			throw AForm::FileIssueException();
		file << "\\  /    \\/  \\   \\/   /  " << std::endl;
		file << " \\/  \\  /    \\  /   /   " << std::endl;
		file << "  \\   \\/      \\/  \\/    " << std::endl;
		file << "   \\  /        \\  /     " << std::endl;
		file << "    ||          ||      " << std::endl;
		file << "   _||_        _||_     " << std::endl;
		file << std::endl;
		file.close();
	}
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &other )
{
	if ( this != &other )
	{
		// Contracts are unique, they can't be copied. This has no effect.
	}
	return *this;
}
