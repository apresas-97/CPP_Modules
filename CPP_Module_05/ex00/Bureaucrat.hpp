#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{

public:

	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	~Bureaucrat();
	Bureaucrat( Bureaucrat const & other );
	Bureaucrat & operator=( Bureaucrat const & other );

private:

	const std::string	_name;
	int					_grade;

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		incrementGrade( void );
	void		decrementGrade( void );

};

std::ostream & operator<<( std::ostream & out, const Bureaucrat & rhs );

#endif // BUREAUCRAT_HPP