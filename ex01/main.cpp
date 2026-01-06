#include "Bureaucrat.hpp"
#include "Form.hpp"
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
		Bureaucrat JeanFrancois("JeanFrancois", 2);
		Form form("useless form", 1, 150);
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
			Form form("useless form", 1, 150);
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
	return (0);
}
