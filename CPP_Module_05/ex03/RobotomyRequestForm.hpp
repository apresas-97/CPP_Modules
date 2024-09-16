#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:

		RobotomyRequestForm( void );
		RobotomyRequestForm( RobotomyRequestForm const &other );
		RobotomyRequestForm( std::string target );
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=( RobotomyRequestForm const &other );

		void			execute( Bureaucrat const & executor ) const;

	private:

		const std::string	_target;

};

#endif // ROBOTOMYREQUESTFORM_HPP
