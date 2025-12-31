#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	protected:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string&, int);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);

		const std::string& getName(void) const;
		int getGrade(void) const;

		void setGrade(int);
		void promote(void);
		void demote(void);

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

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
