
#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Gino"), _grade(75) {
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& bur) : _name(bur._name), _grade(bur._grade) {
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bur) {
	if (this != &bur) {
		_name = bur._name;
		_grade = bur._grade;
	}

	return *this;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat Grade too low\n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat Grade too high\n";
}

const std::string& Bureaucrat::getName(void) const {
	return _name;
}

int Bureaucrat::getGrade(void) const {
	return _grade;
}

void Bureaucrat::incrementGrade(void) {
	_grade -= 1;
	if (_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade(void) {
	_grade += 1;
	if (_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(AForm& form) {

	if (form.getSigned() == true)
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
		std::cout << _name << " couldn't sign " << form.getName() << " because grade is too low\n";
}

void Bureaucrat::executeForm(const AForm& form) {
	form.execute(*this);
	std::cout << _name << " execute " << form.getName() << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur) {

	out << bur.getName() << ", bureaucrat grade " << bur.getGrade();

	return out;
}