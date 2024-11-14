
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {

	private:
		std::string _target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& form);

		RobotomyRequestForm& operator=(const RobotomyRequestForm& form);

		const std::string&	getTarget(void) const;
 		
		void requestRobot(void) const;
		void execute(const Bureaucrat& bur) const;

		~RobotomyRequestForm(void);
};

#endif