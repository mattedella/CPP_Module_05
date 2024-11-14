
#ifndef PRESIDETIALPARDONFORM_HPP
# define PRESIDETIALPARDONFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {

	private:
		std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& form);

		PresidentialPardonForm& operator=(const PresidentialPardonForm& form);

		const std::string& getTarget(void) const;
 		
		void execute(const Bureaucrat& bur) const;

		~PresidentialPardonForm(void);
};

#endif