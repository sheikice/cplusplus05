#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const std::string&, int, int);
		virtual ~Intern(void);
		Intern(const Intern&);
		Intern& operator=(const Intern&);

		AForm *makeForm(const std::string&, const std::string&) const;

	class badAllocationException: public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};

	class badFormNameException: public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};
};

#endif
