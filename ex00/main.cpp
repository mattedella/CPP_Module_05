
#include "Bureaucrat.hpp"

int main() {

	try {
		Bureaucrat* lawyer = new Bureaucrat("John", 34);
		Bureaucrat* medic = new Bureaucrat("Bill", 150);

		std::cout << *lawyer << std::endl;
		std::cout << *medic << std::endl;

		lawyer->incrementGrade();
		medic->decrementGrade();

		std::cout << *lawyer << std::endl;
		std::cout << *medic << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what();
	}
	catch(std::exception& e ) {
		std::cerr << e.what();
	}

	return 0;
}
