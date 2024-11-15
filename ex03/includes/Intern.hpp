
#ifndef INTER_HPP
# define INTER_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern {

    private:
        static AForm* createShrubbery(const std::string& target) {
            return new ShrubberyCreationForm(target);
        };
        static AForm* createRobotomy(const std::string& target) {
            return new RobotomyRequestForm(target);
        };
        static AForm* createPresidential(const std::string& target) {
            return new PresidentialPardonForm(target);
        };

    public:
        typedef AForm* (*FormCreator)(const std::string& target);

        AForm* makeForm(const std::string& formName,const std::string& target);
};

#endif