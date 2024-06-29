#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;

	AForm *sh = intern.makeForm("asdasdasd", "home");

	if (sh)
		std::cout << *sh << "\n";
	delete sh;
	sh = intern.makeForm("ShrubberyCreation", "home");
	if (sh)
		std::cout << *sh << "\n";
	delete sh;
	sh = intern.makeForm("RobotomyRequest", "Karapet");
	if (sh)
		std::cout << *sh << "\n";
	delete sh;
	sh = intern.makeForm("PresidentialPardon", "Dzuk");
	if (sh)
	{
		std::cout << *sh << "\n";
		sh->beSigned(Bureaucrat("Barev", 1));
		sh->execute(Bureaucrat("Barev", 1));
	}
	delete sh;
	sh = intern.makeForm("hello", "home");
	if (sh)
		std::cout << *sh << "\n";
	delete sh;
    return 0;
}