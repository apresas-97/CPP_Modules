#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

public:

	AForm( void );
	AForm( std::string name, std::string target, int gradeToSign, int gradeToExecute );
	AForm( AForm const &other );
	virtual ~AForm();
	AForm & operator=( AForm const &other );

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class FormAlreadySignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class FormNotProperlyConstructedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class FileIssueException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	std::string			getName( void ) const;
	std::string 		getTarget( void ) const;
	bool				getSigned( void ) const;
	int					getGradeToSign( void ) const;
	int					getGradeToExecute( void ) const;

	void				beSigned( Bureaucrat & bureaucrat );
	virtual void		execute( Bureaucrat const & executor ) const = 0;

protected:

	const std::string	_name;
	const std::string	_target;
	bool				_signed;
	const int			_gradeToSign;
	const int 			_gradeToExecute;

private:

};

std::ostream &	operator<<( std::ostream & out, AForm const & rhs );

#endif // AFORM_HPP
