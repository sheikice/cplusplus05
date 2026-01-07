#include "Form.hpp"
#include <iostream>

Form::Form(void):
	_name(""), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (_gradeToSign <= 0 || _gradeToExecute <= 0)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form(void) {}

Form::Form(const Form& other):
	_name(other.getName()), _gradeToSign(other.getGradeToSign()),
	_gradeToExecute(other.getGradeToExecute()) {}

Form& Form::operator=(const Form& other)
{
	(void) other;
	return (*this);
}

const std::string& Form::getName(void) const
{
	return (_name);
}

int Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}


int Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

bool	Form::getIsSigned(void) const
{
	return (_isSigned);
}

void Form::setIsSigned(bool isSigned)
{
	_isSigned = isSigned;
}

void 	Form::beSigned(const Bureaucrat& Bureaucrat)
{
	if (Bureaucrat.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	setIsSigned(true);
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	if (form.getIsSigned() == false)
		os << form.getName() << " is not signed.\n";
	else
		os << form.getName() << " is signed.\n";
	os << "- Grade required to sign is " << form.getGradeToSign() << "\n";
	os << "- Grade required to execute is " << form.getGradeToExecute() << "\n";
	return (os);
}

