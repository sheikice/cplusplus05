#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(): _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	if (grade <= 0)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	setGrade(grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other):
	_name(other.getName()), _grade(other.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	(void) other;
	return (*this);
}

const std::string& Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::setGrade(int grade)
{
	_grade = grade;
}

void Bureaucrat::promote(void)
{
	int newGrade = getGrade() - 1;
	
	if (newGrade <= 0)
		throw GradeTooHighException();
	setGrade(newGrade);
}

void Bureaucrat::demote(void)
{
	int newGrade = getGrade() + 1;
	
	if (newGrade > 150)
		throw GradeTooLowException();
	setGrade(newGrade);
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << "\n";
	}
	catch (std::exception& e)
	{
		std::cout << getName() << " couldn't signed " << form.getName()
			<< " because: " << e.what() << "\n";
	}
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!\n");
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!\n");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
