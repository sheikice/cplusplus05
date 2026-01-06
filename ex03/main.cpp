#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "iostream"

int	main(void)
{
	std::cout << "\n";
	std::cout << "[TEST: grade 0]\n";
	try
	{
		Bureaucrat JeanFrancois("JeanFrancois", 0);

		std::cout << JeanFrancois.getName() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	std::cout << "\n";

	std::cout << "\n";
	std::cout << "[TEST: grade 152]\n";
	try
	{
		Bureaucrat JeanFou("JeanFou", 152);

		std::cout << JeanFou.getName() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	std::cout << "\n";

	std::cout << "\n";
	std::cout << "[TEST: promote from grade 1]\n";
	try
	{
	Bureaucrat JeanFi("JeanFrancois", 1);

		std::cout << JeanFi << "\n";
		std::cout << JeanFi.getName() << " tries to promote\n";
		JeanFi.promote();
		std::cout << JeanFi.getName() << " promoted!\n";
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	std::cout << "\n";

	std::cout << "\n";
	std::cout << "[TEST: demote from grade 150]\n";
	try
	{
		Bureaucrat JeanFi("JeanFrancois", 150);

		std::cout << JeanFi << "\n";
		std::cout << JeanFi.getName() << " tries to demote\n";
		JeanFi.demote();
		std::cout << JeanFi.getName() << " demoted!\n";
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	std::cout << "\n";
	std::cout << "==========================================================================\n";
	std::cout << "\n";
	try
	{
		std::cout << "[TEST: Signing grade too low]\n";
		Bureaucrat JeanFrancois("JeanFrancois", 26);
		PresidentialPardonForm form("target");
		try
		{
			JeanFrancois.signForm(form);
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
		std::cout << "\n";

		std::cout << "\n";
		std::cout << "[TEST: Signing success]\n";
		try
		{
			PresidentialPardonForm form("target");
			JeanFrancois.promote();
			JeanFrancois.signForm(form);
			std::cout << form << "\n";
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	std::cout << "\n";
	std::cout << "==========================================================================\n";
	std::cout << "\n[TEST: execution FAILED ShrubberyCreationForm]\n";
	try
	{
		Bureaucrat JeanFrancois("JeanFrancois", 140);
		AForm *form = NULL;
		AForm *realForm= NULL;

		form = new ShrubberyCreationForm("targeto");
		realForm = new ShrubberyCreationForm(*(static_cast<ShrubberyCreationForm*>(form)));
		try
		{
			JeanFrancois.signForm(*realForm);
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
		try
		{
			JeanFrancois.executeForm(*realForm);
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
		std::cout << "\n[TEST: execution SUCCESS ShrubberyCreationForm]\n";
		try
		{
			std::cout << JeanFrancois.getName() << " is trying to promote from grade " << JeanFrancois.getGrade() << "\n";
			while (1)
				JeanFrancois.promote();
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
		try
		{
			std::cout << JeanFrancois << "\n";
			JeanFrancois.executeForm(*realForm);
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
		delete form;
		delete realForm;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}

	std::cout << "\n[TEST: execution SUCCESS PresidentialPardonForm]\n";
	try
	{
		Bureaucrat JeanFrancois("JeanFrancois", 1);
		AForm *form = NULL;
		AForm *realForm= NULL;

		form = new PresidentialPardonForm("targeto");
		realForm = new PresidentialPardonForm(*(static_cast<PresidentialPardonForm*>(form)));
		try
		{
			JeanFrancois.signForm(*realForm);
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
		try
		{
			JeanFrancois.executeForm(*realForm);
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
		delete form;
		delete realForm;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}

	std::cout << "\n[TEST: execution SUCCESS RobotomyRequestForm]\n";
	try
	{
		Bureaucrat JeanFrancois("JeanFrancois", 1);
		AForm *form = NULL;
		AForm *realForm = NULL;

		form = new RobotomyRequestForm("JeanFrancois");
		realForm = new RobotomyRequestForm(*(static_cast<RobotomyRequestForm*>(form)));
		try
		{
			JeanFrancois.signForm(*realForm);
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
		try
		{
			JeanFrancois.executeForm(*realForm);
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
		delete form;
		delete realForm;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	std::cout << "\n";
	std::cout << "==========================================================================\n";
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

	std::cout << "\n";
	{
		std::cout << "[TEST: SUCCESS construction]\n";
		Intern* intern = NULL;
		AForm* form = NULL;
		try
		{
			intern = new Intern();
			form = intern->makeForm("shrubbery creation", "target");
			std::cout << *form << "\n";
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
