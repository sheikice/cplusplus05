#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int					_gradeToSign;
		const int					_gradeToExecute;
		
	public:
		AForm(void);
		AForm(const std::string&, int, int);
		virtual ~AForm(void);
		AForm(const AForm&);
		AForm& operator=(const AForm&);

		const std::string&	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		bool				getIsSigned(void) const;

		void				setIsSigned(bool);

		void				beSigned(const Bureaucrat&);
		void				execute(const Bureaucrat&) const;
		virtual void		action(void) const = 0;

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

		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif
