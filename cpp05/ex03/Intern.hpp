#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
    struct FormInfo
    {
        std::string name;
        std::function<AForm *(const std::string &)> createFunction;
    };
    static AForm *createShrubberyCreationForm(const std::string &target);
    static AForm *createRobotomyRequestForm(const std::string &target);
    static AForm *createPresidentialPardonForm(const std::string &target);
    static const FormInfo formInfoArray[];

public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    AForm *makeForm(const std::string &name, const std::string &target);
    ~Intern();
};