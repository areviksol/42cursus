#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	Bureaucrat b = Bureaucrat("hello", 1);

	AForm *a = new ShrubberyCreationForm();
	
	std::cout << *a << "\n";
	try
	{
		a->beSigned(b);
		std::cout << "Signed!\n";
		a->execute(b);
		std::cout << "Executed!\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught : " << e.what() << '\n';
	}

	delete a;

	AForm *rob = new RobotomyRequestForm();

	try
	{
		std::cout << *rob << "\n";

		rob->beSigned(b);
		std::cout << "Robot Signed!\n";
		b.executeForm(*rob);
		std::cout << "Robot Executed!\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught : " << e.what() << '\n';
	}

	Bureaucrat buwuehfiwed("Barev", 12);

	PresidentialPardonForm abc(buwuehfiwed.getName());

	while (buwuehfiwed.getGrade() != abc.getGradeNeedToExecute()) buwuehfiwed.increment();

	std::cout << buwuehfiwed.getGrade() << "\n";
	std::cout << abc << "\n";
	try
	{
		abc.beSigned(buwuehfiwed);
		std::cout << "Pardon signed!\n";
		abc.execute(buwuehfiwed);
		std::cout << "Pardon executed!\n";
		buwuehfiwed.executeForm(abc);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Pardon Exception caught : " << e.what() << '\n';
	}
}