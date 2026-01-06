#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "iostream"

int	main(void)
{
	std::cout << "\n";
	{
		std::cout << "[TEST: bad form name]\n";
		Intern* intern = NULL;
		AForm* form = NULL;
		try
		{
			intern = new Intern();
			form = intern->makeForm("truc", "target");
			std::cout << form << "\n";
		}
		catch (std::exception& e)
		{
			std::cout << "It doesn't work because: " << e.what() << "\n";
		}
		delete form;
		delete intern;
	}
	std::cout << "\n";

	std::cout << "\n";
	{
		std::cout << "[TEST: nullptr in string construction]\n";
		Intern* intern = NULL;
		AForm* form = NULL;
		try
		{
			intern = new Intern();
			form = intern->makeForm(NULL, "target");
			std::cout << form << "\n";
		}
		catch (std::exception& e)
		{
			std::cout << "It doesn't work because: " << e.what() << "\n";
		}
		delete form;
		delete intern;
	}
	std::cout << "\n";
	return (0);
}
