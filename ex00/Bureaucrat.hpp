
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat {

	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& bur);

		Bureaucrat& operator=(const Bureaucrat& bur);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		const std::string&	getName(void) const;
		int					getGrade(void) const;

		void incrementGrade(void);
		void decrementGrade(void);

		~Bureaucrat(void);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur);

#endif