#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Default constructor for Intern called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Copy constructor for Intern called" << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Destructor for Intern called" << std::endl;
}

const Intern::FormInfo Intern::formInfoArray[] = {
    {"ShrubberyCreation", createShrubberyCreationForm},
    {"RobotomyRequest", createRobotomyRequestForm},
    {"PresidentialPardon", createPresidentialPardonForm}};

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    for (size_t i = 0; i < sizeof(formInfoArray) / sizeof(formInfoArray[0]); ++i)
    {
        const FormInfo &info = formInfoArray[i];
        if (info.name == name)
        {
            return info.createFunction(target);
        }
    }

    std::cout << "Error: Unknown form name '" << name << "'" << std::endl;
    return nullptr;
}

AForm *Intern::createShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}