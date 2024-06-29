#include "Bureaucrat.hpp"
#include "AForm.hpp"
Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade) : name(_name)
{
    std::cout << "Bureaucrat Parameterized constructor" << std::endl;
    if (_grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (_grade > 150)
    {
        throw GradeTooLowException();
    }
    grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName())
{

    std::cout << "Copy constructor called" << std::endl;
    if (other.getGrade() > 150)
        throw GradeTooLowException();
    if (other.getGrade() < 1)
        throw GradeTooHighException();
    if (this != &other)
        *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{

    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    if (other.getGrade() > 150)
        throw GradeTooLowException();
    if (other.getGrade() < 1)
        throw GradeTooHighException();
    grade = other.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor" << std::endl;
}

std::string const Bureaucrat::getName() const { return (name); }
int Bureaucrat::getGrade() const { return (grade); }
char const *Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade is too high!"); }
char const *Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade is too low!"); }

void Bureaucrat::increment()
{

    std::cout << "Increment" << std::endl;
    if (grade == 1)
        throw GradeTooLowException();
    grade -= 1;
}

void Bureaucrat::decrement()
{
    std::cout << "Decrement" << std::endl;
    if (grade == 150)
        throw GradeTooHighException();
    grade += 1;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bur)
{
    out << bur.getName() << "'s grade is "
        << bur.getGrade() << std::endl;
    return (out);
}

void Bureaucrat::signForm(AForm &f) const
{
    try
    {
        f.beSigned(*this);
        std::cout << getName() << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << name << "couldn’t sign" << f.getName() << "form because" << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}