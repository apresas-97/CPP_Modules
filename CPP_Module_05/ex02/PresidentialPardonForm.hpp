#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:

		PresidentialPardonForm( void );
		PresidentialPardonForm( PresidentialPardonForm const &other );
		PresidentialPardonForm( std::string target );
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=( PresidentialPardonForm const &other );

		void	execute( Bureaucrat const & executor ) const;

	private:

		const std::string	_target;

};

#endif // PRESIDENTIALPARDONFORM_HPP
