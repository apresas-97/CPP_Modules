#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Form
{
public:

	Form( void );
	Form( std::string name, int gradeToSign, int gradeToExecute );
	Form( Form const &other );
	~Form();
	Form & operator=( Form const &other );

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade too high");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade too low");
			}
	};

	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	int			getGradeToSign( void ) const;
	int			getGradeToExecute( void ) const;

	void		beSigned( Bureaucrat &bureaucrat );

private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int 			_gradeToExecute;

};

std::ostream &	operator<<( std::ostream & out, Form const & rhs );

#endif // FORM_HPP
