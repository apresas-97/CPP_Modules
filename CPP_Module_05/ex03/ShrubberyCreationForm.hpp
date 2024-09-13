#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( ShrubberyCreationForm const &other );
		ShrubberyCreationForm( std::string target );
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=( ShrubberyCreationForm const &other );

		void			execute( Bureaucrat const & executor ) const;
		virtual	AForm*	clone( std::string target ) const;

	private:
		
		std::string	_target;

};

#endif // SHRUBBERYCREATIONFORM_HPP
