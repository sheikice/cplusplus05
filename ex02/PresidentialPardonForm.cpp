#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void): AForm("presidentialPardonForm", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("presidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void) other;
	return (*this);
}

const std::string&	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::action(void) const
{
	presidentialAbsolution();
}

void	PresidentialPardonForm::presidentialAbsolution() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}
