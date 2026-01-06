#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "iostream"

int	main(void)
{
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
