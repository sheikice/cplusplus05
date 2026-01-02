#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "iostream"

int	main(void)
{
	try
	{
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
		try
		{
			Form form("useless form", 1, 150);
			JeanFrancois.promote();
			JeanFrancois.signForm(form);
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
	return (0);
}
