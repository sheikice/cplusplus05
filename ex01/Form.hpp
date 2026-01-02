#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		int					_gradeToSign;
		int					_gradeToExecute;
		
	public:
		Form(void);
		Form(const std::string&, int, int);
		~Form(void);
		Form(const Form&);
		Form& operator=(const Form&);

		const std::string&	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		bool				getIsSigned(void) const;

		void				setGradeToSign(int);
		void 				setGradeToExecute(int);
		void				setIsSigned(bool);

		void				beSigned(const Bureaucrat&);

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif
