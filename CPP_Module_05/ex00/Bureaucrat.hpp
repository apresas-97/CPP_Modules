#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{

public:

	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	Bureaucrat( Bureaucrat const & other );
	~Bureaucrat();
	Bureaucrat & operator=( Bureaucrat const & other );

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

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		incrementGrade( void );
	void		decrementGrade( void );

private:

	const std::string	_name;
	int					_grade;

};

std::ostream & operator<<( std::ostream & out, const Bureaucrat & rhs );

#endif // BUREAUCRAT_HPP