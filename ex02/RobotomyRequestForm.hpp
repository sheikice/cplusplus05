#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		const std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string&);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm& operator=(const RobotomyRequestForm&);

		const std::string&	getTarget(void) const;

		void	action(void) const;
		void	robotomy(void) const;
};

#endif
