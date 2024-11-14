
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;


	public:
		AForm(void);
		AForm(const AForm& form);
		AForm(const std::string name, const int gradeSing, const int gradeExec);

		AForm& operator=(const AForm& form);

		class GradeTooLowException : public std::exception {
			
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			
			public:
				virtual const char* what() const throw();
		};

		const std::string&	getName(void) const;
		int 				getGradeS(void) const;
		int		 			getGradeE(void) const;
		bool				getSigned(void) const;

		virtual void beSigned(Bureaucrat& bur);
		virtual void execute(const Bureaucrat& bur) const = 0;

		virtual ~AForm(void) {};

};

std::ostream& operator<<(std::ostream& out, const AForm& form);


#endif