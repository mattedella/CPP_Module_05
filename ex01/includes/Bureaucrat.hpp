
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat {

	private:
		std::string	_name;
		int			_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& bur);

		Bureaucrat& operator=(const Bureaucrat& bur);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		const std::string&	getName(void) const;
		int					getGrade(void) const;

		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form& form);

		~Bureaucrat(void);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur);

#endif