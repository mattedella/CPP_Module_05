
#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PPF", 25, 5) {
    _target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PPF", 25, 5) {
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form) : AForm(form) {
    _target = form._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form) {
    if (this != &form)
        _target = form._target;
    
    return *this;
}

const std::string& PresidentialPardonForm::getTarget(void) const {
    return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat& bur) const {
    if (bur.getGrade() <= this->getGradeE() && this->getSigned() == true) {
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
        return ;
    }

    throw AForm::GradeTooLowException();
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}