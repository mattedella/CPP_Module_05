
#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RRC", 72, 45) {
    _target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RRC", 72, 45) {
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form) : AForm(form) {
    _target = form._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form) {
    if (this != &form)
        _target = form._target;

    return *this;
}

const std::string& RobotomyRequestForm::getTarget(void) const {
    return _target;
}

void RobotomyRequestForm::requestRobot(void) const {
    std::cout << "Bzzz....Fzzzz....Pzzzz....\n\n";

	std::cout << getTarget() << " has been robotomized successfully 50% of the time\n";
}

void RobotomyRequestForm::execute(const Bureaucrat& bur) const {
    if (bur.getGrade() <= this->getGradeE() && this->getSigned() == true) {
        requestRobot();
        return ;
    }

    throw AForm::GradeTooLowException();
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}