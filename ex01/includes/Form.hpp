
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;


	public:
		Form(void);
		Form(const Form& form);
		Form(const std::string name, const int gradeSing, const int gradeExec);

		Form& operator=(const Form& form);

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

		void beSigned(Bureaucrat& bur);

		~Form(void) {};

};

std::ostream& operator<<(std::ostream& out, const Form& form);


#endif