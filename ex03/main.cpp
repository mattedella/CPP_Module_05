
#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

int	main()
{
	try {

		Bureaucrat		lawyer("Gianni", 78);
		Bureaucrat		president("Ciuschi", 1);
		Bureaucrat		bartender("Arturo", 30);

		ShrubberyCreationForm	tree("HOME");
		RobotomyRequestForm		robot("Rob");
		PresidentialPardonForm	Pres("John");

		tree.beSigned(lawyer);
		robot.beSigned(bartender);
		Pres.beSigned(president);

		president.signForm(tree);

		lawyer.executeForm(tree);
		bartender.executeForm(robot);
		president.executeForm(Pres);


	} catch (AForm::GradeTooHighException& high) {
		std::cerr << high.what();
	} catch (AForm::GradeTooLowException& low) {
		std::cerr << low.what();
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what();
	} catch (Bureaucrat::GradeTooLowException& i) {
		std::cerr << i.what();
	}

	return 0;
}
