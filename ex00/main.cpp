#include "Bureaucrat.hpp"
#include "iostream"

int	main(void)
{
	try
	{
	Bureaucrat JeanFrancois("JeanFrancois", 2);

		std::cout << JeanFrancois.getName() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	try
	{
		Bureaucrat JeanFou("JeanFou", 152);

		std::cout << JeanFou.getName() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
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
	return (0);
}
