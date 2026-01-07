#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("robotomyRequestForm", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("robotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void) other;
	return (*this);
}

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::action(void) const
{
	robotomy();
}

void	RobotomyRequestForm::robotomy() const
{
	srand(time(0));
	int randomNum = rand() % 2;

	std::cout << "Bzzzz... Zzzzz... Bzzz.... Pshiiiiiiiiiiii!\n";
	if (randomNum == 1)
		std::cout << _target << " has been robotomised.\n";
	else
		std::cout << "Robotomy has failed.\n";

}
