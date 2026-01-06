#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

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

AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	enum OPTIONS {SHRUBBERY_CREATION, PRESIDENTIAL_PARDON, ROBOTOMY_REQUEST};
	int index = 0;
	typedef AForm* (*ptrFn) (const std::string&);
	static const int	LIST_SIZE = 3;
	AForm*				form = NULL;
	std::string			formList[LIST_SIZE] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	ptrFn fnList[LIST_SIZE] = {&ShrubberyCreationForm::createForm,
		&PresidentialPardonForm::createForm, &RobotomyRequestForm::createForm};
	while (index < LIST_SIZE && formList[index] != formName)
		index++;
	switch (index)
	{
		case SHRUBBERY_CREATION:
			form = (*fnList[index])(target);
			break ;
		case PRESIDENTIAL_PARDON:
			form = (*fnList[index])(target);
			break ;
		case ROBOTOMY_REQUEST:
			form = (*fnList[index])(target);
			break ;
		default:
			throw badFormNameException();
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
