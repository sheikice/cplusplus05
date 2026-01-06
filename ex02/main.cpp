#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "iostream"

int	main(void)
{
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
	return (0);
}
