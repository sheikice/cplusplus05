#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		const std::string	_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string&);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);

		const std::string&	getTarget(void) const;

		void	action(void) const;
		void	presidentialAbsolution(void) const;

		class emptyStringException: public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
};

#endif
