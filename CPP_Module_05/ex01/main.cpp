#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	// Testing limits of the Forms
	try
	{
		// Form formGrade1_0("formGrade10", 1, 0);
		// Form formGrade0_1("formGrade01", 0, 1);
		// Form formGrade151_150("formGrade151_150", 151, 150);
		// Form formGrade150_151("formGrade150_151", 150, 151);
	}
	catch ( std::exception & e )
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
	std::cout << std::endl;

	std::cout << "Creating forms:" << std::endl;
	Form formGrade150("botForm", 150, 150);
	Form formGrade100("lowForm", 100, 100);
	Form formGrade50("midForm", 50, 50);
	Form formGrade10("highForm", 10, 10);
	Form formGrade1("topForm", 1, 1);
	std::cout << std::endl;

	std::cout << "Creating bureaucrats:" << std::endl;
	Bureaucrat buroTop("buroTop", 1); // The highest authority
	Bureaucrat buroHigh("buroHigh", 10);
	Bureaucrat buroMid("buroMid", 50);
	Bureaucrat buroLow("buroLow", 100);
	Bureaucrat buroBot("buroBot", 150); // The lowest authority
	std::cout << std::endl;

	std::cout << "Signing forms:" << std::endl;
	// std::cout << "buroTop can sign any form" << std::endl;
	// buroTop.signForm(formGrade150);
	// buroTop.signForm(formGrade100);
	// buroTop.signForm(formGrade50);
	// buroTop.signForm(formGrade10);
	// buroTop.signForm(formGrade1);

	// std::cout << "buroHigh can sign forms with grade 10 or lower" << std::endl;
	// buroHigh.signForm(formGrade150);
	// buroHigh.signForm(formGrade100);
	// buroHigh.signForm(formGrade50);
	// buroHigh.signForm(formGrade10);
	// buroHigh.signForm(formGrade1);

	// std::cout << "buroMid can sign forms with grade 50 or lower" << std::endl;
	// buroMid.signForm(formGrade150);
	// buroMid.signForm(formGrade100);
	// buroMid.signForm(formGrade50);
	// buroMid.signForm(formGrade10);
	// buroMid.signForm(formGrade1);

	// std::cout << "buroLow can sign forms with grade 100 or lower" << std::endl;
	// buroLow.signForm(formGrade150);
	// buroLow.signForm(formGrade100);
	// buroLow.signForm(formGrade50);
	// buroLow.signForm(formGrade10);
	// buroLow.signForm(formGrade1);

	// std::cout << "buroBot can't sign any form" << std::endl;
	// buroBot.signForm(formGrade150);
	// buroBot.signForm(formGrade100);
	// buroBot.signForm(formGrade50);
	// buroBot.signForm(formGrade10);
	// buroBot.signForm(formGrade1);

	std::cout << std::endl;

	std::cout << "Notice that a form that was already signed can't be signed again:" << std::endl;
	buroTop.signForm(formGrade150);

	std::cout << std::endl;

	return 0;
}