#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "iostream"

int	main(void)
{
	std::cout << "\n";
	{
		std::cout << "[TEST: bad form name]\n";
		Intern* intern;
		AForm* form;
		try
		{
			intern = new Intern();
			form = intern->makeForm("truc", "target");
			std::cout << form << "\n";
			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "It doesn't work because: " << e.what() << "\n";
		}
		delete intern;
	}
	std::cout << "\n";

	std::cout << "\n";
	{
		std::cout << "[TEST: nullptr in string construction]\n";
		Intern* intern;
		AForm* form;
		try
		{
			intern = new Intern();
			form = intern->makeForm(NULL, "target");
			std::cout << form << "\n";
			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "It doesn't work because: " << e.what() << "\n";
		}
		delete intern;
	}
	std::cout << "\n";

	return (0);
}
