
#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/Intern.hpp"

int	main()
{
	try {

		Bureaucrat		lawyer("Gianni", 78);
		Bureaucrat		president("Ciuschi", 1);
		Bureaucrat		bartender("Arturo", 30);
		Intern 			somerandomintern;
		AForm* 			robotomy;
		AForm* 			presidential;
		AForm* 			shrubbery;
		AForm*			school;

		robotomy = somerandomintern.makeForm("robotomy", "Bender");
		presidential = somerandomintern.makeForm("presidential", "Gino");
		shrubbery = somerandomintern.makeForm("shrubbery", "home");
		school = somerandomintern.makeForm("school", "president");


		shrubbery->beSigned(lawyer);
		shrubbery->execute(lawyer);
		robotomy->beSigned(bartender);
		robotomy->execute(bartender);
		presidential->beSigned(president);
		presidential->execute(president);

		delete robotomy;
		delete presidential;
		delete shrubbery;
		delete	school;

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
