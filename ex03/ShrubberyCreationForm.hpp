#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		const std::string	_target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string&);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

		const std::string&	getTarget(void) const;

		void	action(void) const;
		void	plantShrubbery(void) const;

		class badOStreamException: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
};

#endif
