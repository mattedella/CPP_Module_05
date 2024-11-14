
#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

int main() {

	try {

		Bureaucrat* lawyer = new Bureaucrat("John", 34);
		Bureaucrat* medic = new Bureaucrat("Bill", 150);
		Form* law = new Form("Law", 35, 34);

		std::cout << *lawyer << std::endl;
		std::cout << *medic << std::endl;
		
		std::cout << "prima: " << *law << std::endl;

		lawyer->signForm(*law);
		law->beSigned(*lawyer);

		lawyer->incrementGrade();
		// medic->decrementGrade();
		lawyer->signForm(*law);
		
		std::cout << "dopo: " << *law << std::endl;

		std::cout << *lawyer << std::endl;
		std::cout << *medic << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what();
	}
	catch(Bureaucrat::GradeTooHighException& e ) {
		std::cerr << e.what();
	}
	catch(Form::GradeTooHighException& e) {
		std::cerr << e.what();
	}
	catch(Form::GradeTooLowException& e) {
		std::cerr << e.what();
	}

	return 0;
}
