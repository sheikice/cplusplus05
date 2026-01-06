#include "AForm.hpp"
#include <iostream>

AForm::AForm(void):
	_name(""), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (_gradeToSign <= 0 || _gradeToExecute <= 0)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm(void) {}

AForm::AForm(const AForm& other):
	_name(other.getName()), _gradeToSign(other.getGradeToSign()),
	_gradeToExecute(other.getGradeToExecute()) {}

AForm& AForm::operator=(const AForm& other)
{
	(void) other;
	return (*this);
}

const std::string& AForm::getName(void) const
{
	return (_name);
}

int AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

bool	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

void AForm::setGradeToSign(int gradeToSign)
{
	_gradeToSign = gradeToSign;
}

void AForm::setGradeToExecute(int gradeToExecute)
{
	_gradeToExecute = gradeToExecute;
}

void AForm::setIsSigned(bool isSigned)
{
	_isSigned = isSigned;
}

void 	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= getGradeToSign())
		setIsSigned(true);
	else
		throw GradeTooLowException();
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (getIsSigned() == false)
		throw FormNotSignedException();
	else
	{
		if (getGradeToExecute() < executor.getGrade())
			throw GradeTooLowException();
		else
			action();
	}
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form wasn't signed!");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	if (form.getIsSigned() == false)
		os << form.getName() << " is not signed.\n";
	else
		os << form.getName() << " is signed.\n";
	os << "- Grade required to sign is " << form.getGradeToSign() << "\n";
	os << "- Grade required to execute is " << form.getGradeToExecute() << "\n";
	return (os);
}
