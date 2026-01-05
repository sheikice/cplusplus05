#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "iostream"

int	main(void)
{
	std::cout << "\n[Fail signing test]:\n";
	try
	{
		Bureaucrat JeanFrancois("JeanFrancois", 150);
		AForm *form = new ShrubberyCreationForm("targeto");
		AForm *realForm = new ShrubberyCreationForm(*(static_cast<ShrubberyCreationForm*>(form)));
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
			JeanFrancois.signForm(*realForm);
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

	std::cout << "\n[Fail execute test]:\n";
	try
	{
		Bureaucrat JeanFrancois("JeanFrancois", 140);
		AForm *form = new ShrubberyCreationForm("targeto");
		AForm *realForm = new ShrubberyCreationForm(*(static_cast<ShrubberyCreationForm*>(form)));
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

	std::cout << "\n[Success execute test PresidentialPardonForm]:\n";
	try
	{
		Bureaucrat JeanFrancois("JeanFrancois", 1);
		AForm *form = new PresidentialPardonForm("targeto");
		AForm *realForm = new PresidentialPardonForm(*(static_cast<PresidentialPardonForm*>(form)));
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

	std::cout << "\n[Success execute test RobotomyRequestForm]:\n";
	try
	{
		Bureaucrat JeanFrancois("JeanFrancois", 1);
		AForm *form = new RobotomyRequestForm("JeanFrancois");
		AForm *realForm = new RobotomyRequestForm(*(static_cast<RobotomyRequestForm*>(form)));
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
