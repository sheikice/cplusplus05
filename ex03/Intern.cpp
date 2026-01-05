#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(const Intern& other)
{
	(void) other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)	other;
	return (*this);
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const
{
	static const int	LIST_SIZE = 3;
	AForm*				form;
	int					index = 0;
	std::string			formList[LIST_SIZE] = {"shrubbery creation", "presidential pardon", "robotomy request"};

	while (index < LIST_SIZE && formList[index] != formName)
		index++;
	switch (index)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break ;
		case 1:
			form = new PresidentialPardonForm(target);
			break ;
		case 2:
			form = new RobotomyRequestForm(target);
			break ;
		default:
		{
			throw badFormNameException();
			return (NULL);
		}
	}
	if (form == NULL)
		throw badAllocationException();
	return (form);
}

const char* Intern::badAllocationException::what(void) const throw()
{
	return ("Memory allocation failed!");
}

const char* Intern::badFormNameException::what(void) const throw()
{
	return ("This form's name doesn't exist!");
}
