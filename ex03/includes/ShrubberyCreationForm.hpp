
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {

	private:
		std::string _target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& form);

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);

		const std::string& getTarget(void) const;

		void execute(const Bureaucrat& bur) const;

		~ShrubberyCreationForm(void);
};

#endif