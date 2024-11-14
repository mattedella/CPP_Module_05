
#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("SCF", 145, 137) {
    _target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("SCF", 145, 137) {
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : AForm(form) {
	_target = form._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
    if (this != &form)
        _target = form._target;

    return *this;
}

const std::string& ShrubberyCreationForm::getTarget(void) const {
    return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& bur) const {
    if (bur.getGrade() <= this->getGradeE() && this->getSigned() == true) {
        std::string fname = _target + "_shrubbery";
        std::ofstream outFile(fname.c_str());
        if (outFile.is_open()) {
            outFile << "       _-_" << std::endl;
            outFile << "    /~~   ~~\\" << std::endl;
            outFile << " /~~         ~~\\" << std::endl;
            outFile << "{               }" << std::endl;
            outFile << " \\  _-     -_  /" << std::endl;
            outFile << "   ~  \\\\ //  ~" << std::endl;
            outFile << "_- -   | | _- _" << std::endl;
            outFile << "  _ -  | |   -_" << std::endl;
            outFile << "      // \\\\";
            outFile.close();
        }
        else {
            std::cout << "Error opening the file\n";
        }
        return ;
    }
    
    throw AForm::GradeTooLowException();
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}