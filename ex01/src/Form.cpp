
#include "../includes/Form.hpp"

// constructor

Form::Form(void) : _name("default"), _signed(false), _gradeToSign(75), _gradeToExec(75) {}

Form::Form(const std::string name, const int gradeSing, const int gradeExec) : _name(name), _signed(false), _gradeToSign(gradeSing), _gradeToExec(gradeExec) {
	
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& form) : _name(form._name), _signed(form._signed), _gradeToSign(form._gradeToSign), _gradeToExec(form._gradeToExec) {
	
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw Form::GradeTooLowException();
}

// operator

Form& Form::operator=(const Form& form) {
	if (this != &form)
		_signed = form._signed;
	
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << form.getName() << ", signed " << form.getSigned() << ", grade to be signed "
		<< form.getGradeS() << ", grade to be executed " << form.getGradeE();
	
	return out;
}

// exception

const char* Form::GradeTooLowException::what() const throw() {
	return "Form Grade too low\n";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form Grade too high\n";
}

// getter

const std::string& Form::getName(void) const {
	return _name;
}

int Form::getGradeE(void) const {
	return _gradeToExec;
}

int Form::getGradeS(void) const {
	return _gradeToSign;
}

bool Form::getSigned(void) const {
	return _signed;
}

// method

void Form::beSigned(Bureaucrat& bur) {
	if (bur.getGrade() <= _gradeToSign) {
		_signed = true;
		return ;
	}
	
	throw Form::GradeTooLowException();
}
