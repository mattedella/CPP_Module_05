
#include "../includes/AForm.hpp"

// constructor

AForm::AForm(void) : _name("default"), _signed(false), _gradeToSign(75), _gradeToExec(75) {}

AForm::AForm(const std::string name, const int gradeSing, const int gradeExec) : _name(name), _signed(false), _gradeToSign(gradeSing), _gradeToExec(gradeExec) {
	
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& form) : _name(form._name), _signed(form._signed), _gradeToSign(form._gradeToSign), _gradeToExec(form._gradeToExec) {
	
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

// operator

AForm& AForm::operator=(const AForm& form) {
	if (this != &form)
		_signed = form._signed;
	
	return *this;
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
	out << form.getName() << ", signed " << form.getSigned() << ", grade to be signed "
		<< form.getGradeS() << ", grade to be executed " << form.getGradeE();
	
	return out;
}

// exception

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm Grade too low\n";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm Grade too high\n";
}

// getter

const std::string& AForm::getName(void) const {
	return _name;
}

int AForm::getGradeE(void) const {
	return _gradeToExec;
}

int AForm::getGradeS(void) const {
	return _gradeToSign;
}

bool AForm::getSigned(void) const {
	return _signed;
}

// method

void AForm::beSigned(Bureaucrat& bur) {
	if (bur.getGrade() <= _gradeToSign) {
		_signed = true;
		return ;
	}
	
	throw AForm::GradeTooLowException();
}
