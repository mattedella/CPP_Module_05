
#include "../includes/Intern.hpp"

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {

    static const struct {
        const char* name;
        FormCreator create;
    } FormCreator[] = {
        {"shrubbery", &Intern::createShrubbery},
        {"robotomy", &Intern::createRobotomy},
        {"presidential", &Intern::createPresidential}
    };

    for (int i = 0; i < 3; i++) {
        if (formName == FormCreator[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return FormCreator[i].create(target);
        }
    }
    
    std::cout << "Error: undefined form\n";
    return NULL;
}